#include <iostream>
#include "Ingrediente.h"
#include "Ingredientes.h"
#include <fstream>
#include <cmath>
using namespace std;
void MuestraParametros()
{

    cout << "1.- Dime el nombre del fichero con los ingredientes" << endl;
    cout << "2.- Dime el tipo de los ingredientes" << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        MuestraParametros();
        return 0;
    }

    string nf = argv[1];
    ifstream f(nf);

    if (!f)
    {
        cout << "No puedo abrir " << nf << endl;
        return 0;
    }

    string formato;
    f.seekg(0);
    getline(f, formato, '\n');

    Ingredientes all_ingre;
    cout << "Lectura de todos los ingredientes" << endl;
    f >> all_ingre;

    cout << "Los tipos de alimentos son: " << endl;
    cout << all_ingre.getTipos();

    string tipo_bus = argv[2];

    Ingredientes ingre_tipo = all_ingre.getIngredienteTipo(tipo_bus);
    cout << "Los ingredientes de tipo " << tipo_bus << " son: " << endl
         << formato << endl
         << ingre_tipo << endl;

    vector<Ingrediente> ingr = ingre_tipo.getIngredientes();

    pair<string, int> max_c;
    max_c.first = ingr[0].getNombre();
    max_c.second = ingr[0].getCalorias();
    pair<string, int> min_c;
    min_c.first = ingr[0].getNombre();
    min_c.second = ingr[0].getCalorias();

    pair<string, int> max_hc;
    max_hc.first = ingr[0].getNombre();
    max_hc.second = ingr[0].getHc();
    pair<string, int> min_hc;
    min_hc.first = ingr[0].getNombre();
    min_hc.second = ingr[0].getHc();

    pair<string, int> max_p;
    max_p.first = ingr[0].getNombre();
    max_p.second = ingr[0].getProteinas();
    pair<string, int> min_p;
    min_p.first = ingr[0].getNombre();
    min_p.second = ingr[0].getProteinas();

    pair<string, int> max_g;
    max_g.first = ingr[0].getNombre();
    max_g.second = ingr[0].getGrasas();
    pair<string, int> min_g;
    min_g.first = ingr[0].getNombre();
    min_g.second = ingr[0].getGrasas();

    pair<string, int> max_f;
    max_f.first = ingr[0].getNombre();
    max_f.second = ingr[0].getFibra();
    pair<string, int> min_f;
    min_f.first = ingr[0].getNombre();
    min_f.second = ingr[0].getFibra();

    double media_c, media_hc, media_p, media_g, media_f;
    int suma_c = 0, suma2_c = 0;
    int suma_hc = 0, suma2_hc = 0;
    int suma_p = 0, suma2_p = 0;
    int suma_g = 0, suma2_g = 0;
    int suma_f = 0, suma2_f = 0;

    for (int i = 0; i < ingr.size(); i++)
    {

        suma_c += ingr[i].getCalorias();
        suma2_c += pow(ingr[i].getCalorias(), 2);
        suma_hc += ingr[i].getHc();
        suma2_hc += pow(ingr[i].getHc(), 2);
        suma_p += ingr[i].getProteinas();
        suma2_p += pow(ingr[i].getProteinas(), 2);
        suma_g += ingr[i].getGrasas();
        suma2_g += pow(ingr[i].getGrasas(), 2);
        suma_f += ingr[i].getFibra();
        suma2_f += pow(ingr[i].getFibra(), 2);

        if (ingr[i].getCalorias() > max_c.second)
        {
            max_c.second = ingr[i].getCalorias();
            max_c.first = ingr[i].getNombre();
        }

        if (ingr[i].getCalorias() < min_c.second)
        {
            min_c.second = ingr[i].getCalorias();
            min_c.first = ingr[i].getNombre();
        }

        if (ingr[i].getHc() > max_hc.second)
        {
            max_hc.second = ingr[i].getHc();
            max_hc.first = ingr[i].getNombre();
        }

        if (ingr[i].getHc() < min_hc.second)
        {
            min_hc.second = ingr[i].getHc();
            min_hc.first = ingr[i].getNombre();
        }

        if (ingr[i].getProteinas() > max_p.second)
        {
            max_p.second = ingr[i].getProteinas();
            max_p.first = ingr[i].getNombre();
        }

        if (ingr[i].getProteinas() < min_p.second)
        {
            min_p.second = ingr[i].getProteinas();
            min_p.first = ingr[i].getNombre();
        }

        if (ingr[i].getGrasas() > max_g.second)
        {
            max_g.second = ingr[i].getGrasas();
            max_g.first = ingr[i].getNombre();
        }

        if (ingr[i].getGrasas() < min_g.second)
        {
            min_g.second = ingr[i].getGrasas();
            min_g.first = ingr[i].getNombre();
        }

        if (ingr[i].getFibra() > max_f.second)
        {
            max_f.second = ingr[i].getFibra();
            max_f.first = ingr[i].getNombre();
        }

        if (ingr[i].getFibra() < min_f.second)
        {
            max_f.second = ingr[i].getFibra();
            max_f.first = ingr[i].getNombre();
        }
    }

    double n = ingr.size();

    media_c = suma_c / n;
    media_hc = suma_hc / n;
    media_p = suma_p / n;
    media_g = suma_g / n;
    media_f = suma_f / n;

    double desv_c = sqrt(suma2_c / n - pow(media_c, 2));
    double desv_hc = sqrt(suma2_c / n - pow(media_hc, 2));
    double desv_p = sqrt(suma2_p / n - pow(media_p, 2));
    double desv_g = sqrt(suma2_g / n - pow(media_g, 2));
    double desv_f = sqrt(suma2_f / n - pow(media_f, 2));

    cout << "--------------------------ESTADISTICA--------------------------" << endl;
    cout << "Tipo de alimento: " << tipo_bus << endl;
    cout << "Promedio +- Desviacion" << endl;
    cout << "Calorias: " << media_c << "+-" << desv_c << endl;
    cout << "Hidratos de Carbono: " << media_hc << "+-" << desv_hc << endl;
    cout << "Proteínas: " << media_p << "+-" << desv_p << endl;
    cout << "Fibra: " << media_f << "+-" << desv_f << endl;
    cout << "Grasas: " << media_g << "+-" << desv_g << endl;
    cout << "--------------------------MAXIMOS VALORES--------------------------" << endl;
    cout << "Calorias (Alimento): " << max_c.second << "--->" << max_c.first << endl;
    cout << "Hidratos de Carbono (Alimento): " << max_hc.second << "--->" << max_hc.first << endl;
    cout << "Proteínas (Alimento): " << max_p.second << "--->" << max_p.first << endl;
    cout << "Fibra (Alimento): " << max_f.second << "--->" << max_f.first << endl;
    cout << "Grasas (Alimento): " << max_g.second << "--->" << max_g.first << endl;
    cout << "--------------------------MINIMOS VALORES--------------------------" << endl;
    cout << "Calorias (Alimento): " << min_c.second << "--->" << min_c.first << endl;
    cout << "Hidratos de Carbono (Alimento): " << min_hc.second << "--->" << min_hc.first << endl;
    cout << "Proteínas (Alimento): " << min_p.second << "--->" << min_p.first << endl;
    cout << "Fibra (Alimento): " << min_f.second << "--->" << min_f.first << endl;
    cout << "Grasas (Alimento): " << min_g.second << "--->" << min_g.first << endl;
}