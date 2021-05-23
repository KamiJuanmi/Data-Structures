#include "Ingrediente.h"

Ingrediente::Ingrediente(string nombre, float num_cal, float p_hc, float p_prot, float p_gr, float p_fib, string tipo)
{
    this->nombre = nombre;
    this->num_cal = num_cal;
    this->p_hc = p_hc;
    this->p_prot = p_prot;
    this->p_gr = p_gr;
    this->p_fib = p_fib;
    this->tipo = tipo;
}

void Ingrediente::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Ingrediente::setCalorias(float cal)
{
    this->num_cal = cal;
}

void Ingrediente::setFibra(float fib)
{
    this->p_fib = fib;
}

void Ingrediente::setGrasas(float gras)
{
    this->p_gr = gras;
}

void Ingrediente::setHc(float hid)
{
    this->p_hc = hid;
}

void Ingrediente::setProteinas(float prot)
{
    this->p_prot = prot;
}

void Ingrediente::setTipo(string tipo)
{
    this->tipo = tipo;
}

ostream &operator<<(ostream &f, const Ingrediente &uno)
{
    f << uno.getNombre() << ";"
      << uno.getCalorias() << ";"
      << uno.getHc() << ";"
      << uno.getProteinas() << ";"
      << uno.getGrasas() << ";"
      << uno.getProteinas() << ";"
      << uno.getFibra() << ";"
      << uno.getTipo() << "\n";

    return f;
}

istream &operator>>(istream &f, Ingrediente &uno)
{
    string str;

    getline(f, str, ';');
    uno.setNombre(str);
    getline(f, str, ';');
    uno.setCalorias(stof(str));
    getline(f, str, ';');
    uno.setHc(stof(str));
    getline(f, str, ';');
    uno.setProteinas(stof(str));
    getline(f, str, ';');
    uno.setGrasas(stof(str));
    getline(f, str, ';');
    uno.setFibra(stof(str));
    getline(f, str, '\n');
    uno.setTipo(str);

    return f;
}

