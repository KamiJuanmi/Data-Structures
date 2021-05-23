#include "Receta.h"

istream &operator>>(istream &f, Receta &r)
{
    string str;
    pair<string, unsigned int> ing;

    getline(f, str, ';');
    r.setCode(str);

    r.InicializaInstrucciones();

    getline(f, str, ';');
    r.setPlato(stoi(str));

    getline(f, str, ';');
    r.setNombre(str);

    getline(f, str, '\n');

    char *pch;
    char ayuda[str.length() + 1];

    strcpy(ayuda, str.c_str());

    pch = strtok(ayuda, ";\n");

    string aux;

    while (pch != NULL)
    {
        aux = pch;
        string num;

        int pos = aux.find_last_of(" "); //BUSCAMOS DONDE EMPIEZA EL NUMERO
        num = aux.substr(pos + 1);
        aux = aux.substr(0, aux.length() - num.length() - 1);

        ing.first = aux;
        ing.second = stoi(num);

        r.addIngrediente(ing);

        pch = strtok(NULL, ";\n");
    }

    return f;
}

ostream &operator<<(ostream &f, const Receta &r)
{
    list<pair<string, unsigned int>> aux = r.getIngredientes();

    f << FBLU("CODE: ") << r.getCode() << FBLU(" NOMBRE: ") << r.getNombre() << FBLU("PLATO: ") << r.getPlato() << endl;

    f << UNDL(BOLD("Ingredientes: ")) << endl
      << endl;

    for (list<pair<string, unsigned int>>::const_iterator it = aux.cbegin(); it != aux.cend(); it++)
    {
        f << (*it).first << " " << (*it).second << endl;
    }

    f << UNDL(BOLD("Información Nutricional: ")) << endl
      << endl;

    f << "Calorias: " << r.getCalorias() << endl;
    f << "Hidratos de Carbono: " << r.getHC() << endl;
    f << "Grasas: " << r.getGrasas() << endl;
    f << "Proteina: " << r.getProteinas() << endl;
    f << "Fibra: " << r.getFibra() << endl;

    f << UNDL(BOLD("Pasos a seguir: ")) << endl
      << endl;

    f << r.getInstrucciones();

    return f;
}

Receta::Receta(const Instrucciones &inst)
{
    this->inst = inst;
}

void Receta::InicializaInstrucciones()
{
    Instrucciones aux(this->code);
    this->inst = aux;
}

Instrucciones Receta::getInstrucciones() const
{
    return this->inst;
}

list<pair<string, unsigned int>> Receta::getIngredientes() const
{
    return this->ings;
}

string Receta::getCode() const
{
    return this->code;
}

unsigned int Receta::getPlato() const
{
    return this->plato;
}

string Receta::getNombre() const
{
    return this->nombre;
}

float Receta::getCalorias() const
{
    return this->calorias;
}

float Receta::getHC() const
{
    return this->hc;
}

float Receta::getGrasas() const
{
    return this->grasas;
}

float Receta::getProteinas() const
{
    return this->proteinas;
}

float Receta::getFibra() const
{
    return this->fibra;
}

float Receta::getRelacion() const
{
    return (this->getProteinas() / this->getHC());
}

int Receta::ningredientes() const
{
    return this->ings.size();
}

void Receta::setCode(string code)
{
    this->code = code;
}

void Receta::setPlato(unsigned int plato)
{
    this->plato = plato;
}

void Receta::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Receta::addIngrediente(pair<string, unsigned int> ing)
{
    this->ings.push_back(ing);
}

void Receta::setCalorias(float calorias)
{
    this->calorias = calorias;
}

void Receta::setHC(float hc)
{
    this->hc = hc;
}

void Receta::setGrasas(float grasas)
{
    this->grasas = grasas;
}

void Receta::setProteinas(float proteinas)
{
    this->proteinas = proteinas;
}

void Receta::setFibra(float fibra)
{
    this->fibra = fibra;
}

Receta Receta::Fusion(const Receta &otra)
{
    Receta aux(this->inst.Fusion(otra.inst));

    aux.setCode("F_" + this->code + "_" + otra.code);
    aux.setNombre("Fusion " + this->nombre + " y " + otra.nombre);
    aux.setPlato(this->plato);
    aux.setCalorias(this->calorias + otra.calorias);
    aux.setHC(this->hc + otra.hc);
    aux.setGrasas(this->grasas + otra.grasas);
    aux.setProteinas(this->proteinas + otra.proteinas);
    aux.setFibra(this->fibra + otra.fibra);

    pair<string, unsigned int> ingre;
    bool go;

    for (Receta::const_iterador it = this->cbegin(); it != this->cend(); ++it)
    {
        ingre.first = (*it).first;
        ingre.second = (*it).second;

        go = true;
        for (Receta::const_iterador ot = otra.cbegin(); ot != otra.cend() && go; ++ot)
        {
            if ((*ot).first == ingre.first)
            {
                ingre.second += (*ot).second;
                go = false;
            }
        }

        aux.addIngrediente(ingre);
    }

    return aux;
}

/**
 * NOTA: Somos conscientes de la ineficiencia del código inferior.
 * Sin embargo, consideramos que no se debería verificar que los ingredientes que se manjean sean correctos o no
 * pues se presupone por precondicion que éstos ya lo son. De no serlo, el comportamiento del programa sería indefinido.
 * Se ha incluido este método público al TDA Receta siguiendo las indicaciones que se nos dieron en el último correo electrónico,
 * pero este problema se podría haber evitado manteniendo una consistencia en los archivos que contenian los datos con los que trabajamos.
 * 
 * Tambien consdideramos que esta verificación no debería llevarse a cabo en el momento de fusionar, sino que tendría que ser en el momento 
 * de creación del objeto recetas, ya que si falta un ingrediente como es el caso de la R6, los datos nutricionales de esta receta están mal.
 * 
 * Del mismo modo, hemos ido encontrando constantes errores de formato en los archivos de datos que se nos han proporcionado cuya
 * corrección ha consumido grandes cantidades de tiempo.
 * 
 * Se nos exige mucho rigor en nuestros trabajos y errores de ese calibre no habrían sido consentidos de haber ocurrido al contrario.
 * Rogamos que esto sea tenido en cuenta para posteriores prácticas de la asignatura.
 */
pair<bool, string> Receta::correcta(const Ingredientes &all_ingre)
{
    bool correcta = true;
    string nom_ingr = "";

    for (Receta::const_iterador it = this->cbegin(); it != this->cend() && correcta; ++it)
    {
        correcta = false;

        for (Ingredientes::const_iterador it2 = all_ingre.cbegin(); it2 != all_ingre.cend() && !correcta; ++it2)
        {
            if ((*it).first == (*it2).getNombre())
            {
                correcta = true;
            }
        }

        if (!correcta)
        {
            nom_ingr = (*it).first;
        }
    }

    return (make_pair(correcta, nom_ingr));
}
