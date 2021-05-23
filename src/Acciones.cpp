#include "Acciones.h"
#include <fstream>

using namespace std;

Acciones::Acciones(string ruta)
{
    ifstream f_Acc(ruta);

    f_Acc >> *this;

    f_Acc.close();
}

void Acciones::insert(Acc_Arid::value_type nuevo)
{
    this->datos.insert(nuevo);
}

Acc_Arid::mapped_type &Acciones::operator[](const Acc_Arid::key_type &key)
{
    return this->datos[key];
}

const Acc_Arid::mapped_type &Acciones::operator[](const Acc_Arid::key_type &key) const
{
    return this->datos.at(key);
}

bool Acciones::empty() const
{
    return this->datos.empty();
}

istream &operator>>(istream &f, Acciones &unas)
{
    string str;
    char i;

    do
    {
        getline(f, str, '\n');

        string num;
        int pos = str.find_last_of(" "); //BUSCAMOS DONDE EMPIEZA EL NUMERO
        num = str.substr(pos + 1);
        str = str.substr(0, str.length() - num.length() - 1);

        unsigned char numero = num[0];

        unas.insert(pair<string, unsigned char>(str, numero));

        i = f.peek();

    } while (i != EOF);

    return f;
}

ostream &operator<<(ostream &f, const Acciones &unas)
{
    Acciones::const_iterador it;

    for (it = unas.cbegin(); it != unas.cend(); ++it)
    {
        cout << (*it).first << " ARIDAD->" << (*it).second << endl;
    }

    return f;
}

