#include "Instrucciones.h"

Acciones Instrucciones::acc = Acciones();

string Instrucciones::ruta = string();

Instrucciones::Instrucciones(string codigo_Receta)
{
    string nombre_INS = ruta + codigo_Receta + "m.txt";
    ifstream f(nombre_INS);

    if (!f)
    {
        cout << "No puedo abrir " << nombre_INS << endl;
        exit(EXIT_FAILURE);
    }

    stack<Arbol> pila;
    char i;
    string linea, accion, ingre;
    string aridad_aux;
    int pos, aridad;

    do
    {
        aridad_aux.clear();

        getline(f, linea, '\n');
        pos = linea.find_first_of(" ");
        Arbol aux;

        if (pos == -1)
        {
            accion = linea;
            ingre = string();

            aridad_aux += acc[accion];
            aridad = stoi(aridad_aux);

            Arbol aux1(accion);

            aux = aux1;

            if (aridad == 2)
            {
                aux.Insertar_Hd(aux.getRaiz(), pila.top());
                pila.pop();

                aux.Insertar_Hi(aux.getRaiz(), pila.top());
                pila.pop();
            }
            else
            {
                aux.Insertar_Hi(aux.getRaiz(), pila.top());
                pila.pop();
            }
        }
        else
        {
            ingre = linea.substr(pos + 1);
            accion = linea.substr(0, linea.length() - ingre.length() - 1);

            Arbol aux1(accion);

            aux = aux1;

            aridad_aux += acc[accion];
            aridad = stoi(aridad_aux);

            if (aridad == 2)
            {
                aux.Insertar_Hi(aux.getRaiz(), pila.top());
                pila.pop();

                aux.Insertar_Hd(aux.getRaiz(), ingre);
            }
            else
            {
                aux.Insertar_Hi(aux.getRaiz(), ingre);
            }
        }

        pila.push(aux);

        i = f.peek();

    } while (i != EOF);

    f.close();

    this->datos = pila.top();
}

Instrucciones::Instrucciones(const Arbol &dat)
{
    this->datos = dat;
}

void Instrucciones::InicializaAcciones(string path)
{
    Acciones acc_aux(path);
    acc = acc_aux;
}

void Instrucciones::InicializaRuta(string path)
{
    ruta = path;
}

Arbol Instrucciones::getArbol() const
{
    return this->datos;
}

Instrucciones &Instrucciones::operator=(const Instrucciones &otra)
{
    if (this->datos != otra.datos)
    {
        this->datos = otra.datos;
    }

    return *this;
}

Instrucciones Instrucciones::Fusion(const Instrucciones &otras)
{
    Arbol aux("Acompañar");
    Arbol aux2(otras.datos);
    Arbol aux3(this->datos);

    aux.Insertar_Hi(aux.getRaiz(), aux3);
    aux.Insertar_Hd(aux.getRaiz(), aux2);

    return Instrucciones(aux);
}

ostream &Instrucciones::Postorden(ostream &f, Arbol::nodo v) const
{
    static string ing;
    if (!v.nulo())
    {
        Postorden(f, v.hi());
        Postorden(f, v.hd());

        if (v.hi().nulo() && v.hd().nulo())
        {
            ing = *v;
        }
        else
        {
            f << *v << " " << ing << endl;
            ing.clear();
        }
    }

    return f;
}

ostream &operator<<(ostream &f, const Instrucciones &unas)
{
    return unas.Postorden(f, unas.getArbol().getRaiz());
}
