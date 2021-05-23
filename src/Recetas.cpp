#include "Recetas.h"

int Recetas::size()
{
    return this->datos.size();
}

Recetas::Recetas(const Recetas &otra)
{
    this->datos = otra.datos;
}

Recetas &Recetas::operator=(const Recetas &otra)
{
    this->datos = otra.datos;

    return *this;
}

void Recetas::clear()
{
    this->datos.clear();
}

float Recetas::getRelacion() const
{
    float rel = 0;

    for (Recetas::const_iterador it = this->cbegin(); it != this->cend(); ++it)
    {
        rel += (*it).getRelacion();
    }

    return rel;
}

float Recetas::getCalorias() const
{
    float cal = 0;

    for (Recetas::const_iterador it = this->cbegin(); it != this->cend(); ++it)
    {
        cal += (*it).getCalorias();
    }

    return cal;
}

float Recetas::getProteinas() const
{
    float prot = 0;

    for (Recetas::const_iterador it = this->cbegin(); it != this->cend(); ++it)
    {
        prot += (*it).getProteinas();
    }

    return prot;
}

float Recetas::getHC() const
{
    float hc = 0;

    for (Recetas::const_iterador it = this->cbegin(); it != this->cend(); ++it)
    {
        hc += (*it).getHC();
    }

    return hc;
}

const Receta &Recetas::operator[](string code) const
{
    return this->datos.at(code);
}

Receta &Recetas::operator[](string code)
{
    return this->datos.at(code);
}

void Recetas::borrar(string code)
{
    map<string, Receta>::iterator it;
    it = this->datos.find(code);

    this->datos.erase(it);
}

void Recetas::addReceta(const pair<string, Receta> &una)
{
    this->datos.insert(map<string, Receta>::value_type(una.first, una.second));
}

istream &operator>>(istream &f, Recetas &una)
{
    while (!f.eof())
    {
        Receta aux;
        f >> aux;
        una.addReceta(make_pair(aux.getCode(), aux));
    }

    return f;
}

ostream &operator<<(ostream &f, const Recetas &una)
{
    for (Recetas::const_iterador it = una.cbegin(); it != una.cend(); ++it)
    {
        f << *it;
    }

    return f;
}
