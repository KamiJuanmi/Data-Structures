#include "Ingredientes.h"

int Ingredientes::size()
{
    return this->datos.size();
}

Ingrediente Ingredientes::get(string nombre) const
{
    return this->datos[getPos(nombre, 0, this->datos.size() - 1).first];
}

Ingrediente Ingredientes::get(int i) const
{
    return this->datos[i];
}

void Ingredientes::insertar(const Ingrediente &ing)
{
    pair<int, bool> pos_d(0, false);
    int pos_i = 0;

    if (this->datos.size() > 0)
    {
        pos_d = getPos(ing.getNombre(), 0, (int)(this->datos.size() - 1));
        pos_i = 0;

        if (!pos_d.second)
        {
            this->datos.insert(this->datos.begin() + pos_d.first, ing);

            for (size_t i = 0; i < this->indices.size(); i++)
            {
                if (this->indices[i] >= pos_d.first)
                    this->indices[i]++;
            }

            pos_i = getPos(pos_d.first, 0, this->indices.size() - 1);

            this->indices.insert(this->indices.begin() + pos_i, pos_d.first);
        }
    }
    else
    {
        this->datos.insert(this->datos.begin() + pos_d.first, ing);
        this->indices.insert(this->indices.begin() + pos_i, pos_d.first);
    }
}

pair<int, bool> Ingredientes::getPos(string nombre, int ini, int fin) const
{
    pair<int, bool> posicion(ini, false);
    int medio;
    string nom_pos;
    while (!posicion.second && ini <= fin)
    {
        medio = (ini + fin) / 2;
        nom_pos = this->datos[medio].getNombre();

        if (nom_pos == nombre)
        {
            posicion.first = medio;
            posicion.second = true;
        }
        else if (nom_pos < nombre)
        {

            ini = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
    }

    if (ini > fin)
    {
        posicion.first = ini;
    }

    return posicion;
}

int Ingredientes::getPos(int index, int ini, int fin) const
{
    string tipo_bus;
    string tipo_var;
    string nombre_bus;
    string nombre_var;
    nombre_bus = this->datos[index].getNombre();
    tipo_bus = this->datos[index].getTipo();
    int medio;
    int pos;

    if (ini <= fin)
    {
        medio = (fin + ini) / 2;

        if (this->indices[medio] == index)
        {
            pos = medio;
        }

        tipo_var = this->datos[this->indices[medio]].getTipo();
        nombre_var = this->datos[this->indices[medio]].getNombre();

        if (tipo_bus == tipo_var)
        {
            if (nombre_bus < nombre_var)
            {
                pos = getPos(index, ini, medio - 1);
            }
            else if (nombre_bus > nombre_var)
            {
                pos = getPos(index, medio + 1, fin);
            }
        }
        else if (tipo_bus < tipo_var)
        {
            pos = getPos(index, ini, medio - 1);
        }
        else
        {
            pos = getPos(index, medio + 1, fin);
        }
    }
    else
    {
        pos = ini;
    }

    return pos;
}

void Ingredientes::borrar(string nombre)
{
    int pos_d = this->getPos(nombre, 0, this->datos.size() - 1).first;
    int pos_i = this->getPos(pos_d, 0, this->datos.size() - 1);

    //BORRAMOS DEL PRIMER VECTOR PUESTO QUE CON ESE YA NO TENEMOS QUE HACER NADA

    this->datos.erase(this->datos.begin() + pos_d);

    //PASO INVERSO AL ADD, TODOS LOS QUE SEAN MAYORES QUE EL INDICE SE DECREMENTAN EN 1

    for (vector<int>::iterator it = this->indices.begin(); it != this->indices.end(); it++)
    {
        if (*it >= pos_d)
            *it--;
    }

    this->indices.erase(this->indices.begin() + pos_i);
}

void Ingredientes::ImprimirPorTipo(ostream &f) const
{
    for (vector<Ingrediente>::const_iterator it = this->datos.begin(); it != this->datos.end(); it++)
    {
        f << *it;
    }
}

Ingredientes Ingredientes::getIngredienteTipo(string tipo) const
{
    Ingredientes ret2;

    for (vector<Ingrediente>::const_iterator it = this->datos.begin(); it != this->datos.end(); it++)
    {
        if ((*it).getTipo() == tipo)
        {
            ret2.insertar(*it);
        }
    }

    return ret2;
}

vector<string> Ingredientes::getTipos() const
{
    vector<string> tipos;
    int j = 0;

    for (size_t i = 0; i < this->indices.size(); i++)
    {
        if (i == 0)
        {
            tipos.push_back(this->datos[this->indices[i]].getTipo());
        }
        else if (tipos[j] != this->datos[this->indices[i]].getTipo())
        {
            tipos.push_back(this->datos[this->indices[i]].getTipo());
            j++;
        }
    }

    return tipos;
}

Ingrediente Ingredientes::operator[](int i) const
{
    return this->get(i);
}

Ingrediente &Ingredientes::operator[](int i)
{
    return this->datos[i];
}

vector<Ingrediente> Ingredientes::getIngredientes() const
{
    return this->datos;
}

ostream &operator<<(ostream &f, const Ingredientes &ing)
{
    vector<Ingrediente> aux;
    aux = ing.getIngredientes();
    for (vector<Ingrediente>::const_iterator it = aux.begin(); it < aux.end(); it++)
    {
        f << *it;
    }
    return f;
}

istream &operator>>(istream &f, Ingredientes &ing)
{
    string linea;
    getline(f, linea);

    Ingrediente aux;
    int i = f.peek();

    while (i != EOF)
    {
        f >> aux;
        ing.insertar(aux);
        i = f.peek();
    }

    return f;
}
