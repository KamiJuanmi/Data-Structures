#include <iostream>
#include <fstream>
#include <Receta.h>
#include <Recetas.h>
#include <Ingrediente.h>
#include <Ingredientes.h>

using namespace std;

int main(int argc, const char **argv)
{
    if (argc != 4)
    {
        cerr << "\nError. Parámetros incorrectos.";
        exit(1);
    }

    fstream f1(argv[1]), f2(argv[2]);

    if (!f1 || !f2)
    {
        cerr << "\nError en la apertura de los archivos.";
        exit(1);
    }

    Ingredientes todos;
    f2 >> todos;

    Recetas conjunto;
    f1 >> conjunto;

    f1.close();
    f2.close();

    bool primero = true;
    Recetas mejor;

    float calorias = 0, fibra = 0, hc = 0, grasas = 0, proteinas = 0;

    for (Recetas::iterador it = conjunto.begin(); it != conjunto.end(); ++it)
    {
        cout << "\nValores nutricionales de la receta " << *it << " son:" << endl;

        for (Receta::iterador oth = (*it).begin(); oth != (*it).end(); ++oth)
        {
            calorias += ((todos.get((*oth).first)).getCalorias() * (*oth).second) / 100;

            fibra += ((todos.get((*oth).first)).getFibra() * (*oth).second) / 100;

            hc += ((todos.get((*oth).first)).getHc() * (*oth).second) / 100;

            grasas += ((todos.get((*oth).first)).getGrasas() * (*oth).second) / 100;

            proteinas += ((todos.get((*oth).first)).getProteinas() * (*oth).second) / 100;
        }

        (*it).setCalorias(calorias);
        cout << "Calorias " << calorias;
        calorias = 0;

        (*it).setFibra(fibra);
        cout << "\tFibra " << fibra;
        fibra = 0;

        (*it).setHC(hc);
        cout << "\tHidratos de Carbono " << hc;
        hc = 0;

        (*it).setGrasas(grasas);
        cout << "\tGrasas " << grasas;
        grasas = 0;

        (*it).setProteinas(proteinas);
        cout << "\t Proteinas " << proteinas;
        proteinas = 0;

        if ((*it).getCalorias() / atoi(argv[3]) <= 1)
        {
            if (primero)
            {
                primero = false;
                mejor.addReceta(make_pair((*it).getNombre(), (*it)));
            }
            else
            {
                Recetas conjunto_suma_nueva(mejor);
                conjunto_suma_nueva.addReceta(make_pair((*it).getNombre(), (*it)));
                Recetas conjunto_nueva;
                conjunto_nueva.addReceta(make_pair((*it).getNombre(), (*it)));

                if (conjunto_suma_nueva.getCalorias() <= atof(argv[3]))
                {
                    mejor = conjunto_suma_nueva;
                }
                else
                {
                    if (conjunto_nueva.getRelacion() > mejor.getRelacion())
                    {
                        mejor = conjunto_nueva;
                    }
                }
            }
        }

        cout << endl
             << endl;
    }

    if (mejor.size() > 0)
    {
        cout << "Las recetas que cumplen los requisitos son: \n"
             << mejor;
        cout << "Calorias: " << mejor.getCalorias() << " Proteinas: " << mejor.getProteinas() << endl;
    }
    else
    {
        cout << "No se han encontrado apropiadas" << endl;
    }
}