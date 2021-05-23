#include <iostream>
#include "Receta.h"
#include "Recetas.h"
#include "Ingrediente.h"
#include "Ingredientes.h"
#include "Instrucciones.h"
#include "color.h"

using namespace std;

int main(int argc, char **argv)
{
    //argv[1] = Acciones
    //argv[2] = Recetas
    //argv[3] = Ingredientes
    //argv[4] = Instrucciones

    //*************************************************************************
    //APARTADO 1
    //*************************************************************************

    Instrucciones::InicializaAcciones(argv[1]);
    Instrucciones::InicializaRuta(argv[4]);

    //*************************************************************************
    //APARTADO 2
    //*************************************************************************

    string nf_ingr = argv[3];
    ifstream f_ingr(nf_ingr);

    if (!f_ingr)
    {
        cout << "No puedo abrir " << nf_ingr << endl;
        return 0;
    }

    Ingredientes all_ingre;
    cout << "Lectura de todos los ingredientes" << endl;
    f_ingr >> all_ingre;

    //*************************************************************************
    //APARTADO 3
    //*************************************************************************

    string nf_rec = argv[2];
    ifstream f_rec(nf_rec);

    if (!f_rec)
    {
        cout << "No puedo abrir " << nf_rec << endl;
        return 0;
    }

    Recetas r_all;
    cout << "Lectura de todas las recetas" << endl;
    f_rec >> r_all;

    //*************************************************************************
    //APARTADO 4
    //*************************************************************************
    float calorias = 0, fibra = 0, hc = 0, grasas = 0, proteinas = 0;

    for (Recetas::iterador it = r_all.begin(); it != r_all.end(); ++it)
    {
        for (Receta::iterador oth = (*it).begin(); oth != (*it).end(); ++oth)
        {
            calorias += ((all_ingre.get((*oth).first)).getCalorias() * (*oth).second) / 100;

            fibra += ((all_ingre.get((*oth).first)).getFibra() * (*oth).second) / 100;

            hc += ((all_ingre.get((*oth).first)).getHc() * (*oth).second) / 100;

            grasas += ((all_ingre.get((*oth).first)).getGrasas() * (*oth).second) / 100;

            proteinas += ((all_ingre.get((*oth).first)).getProteinas() * (*oth).second) / 100;
        }

        (*it).setCalorias(calorias);
        calorias = 0;

        (*it).setFibra(fibra);
        fibra = 0;

        (*it).setHC(hc);
        hc = 0;

        (*it).setGrasas(grasas);
        grasas = 0;

        (*it).setProteinas(proteinas);
        proteinas = 0;
    }
    //*************************************************************************
    //APARTADO 5
    //*************************************************************************

    for (Recetas::const_iterador it = r_all.cbegin(); it != r_all.cend(); ++it)
    {
        cout << FBLU("CODE: ") << (*it).getCode() << FBLU(" NOMBRE: ") << (*it).getNombre() << FBLU(" PLATO: ") << (*it).getPlato() << endl;
    }

    cout << "Pulse una tecla para continuar" << endl;
    cin.get();

    //*************************************************************************
    //APARTADO 6 y 7
    //*************************************************************************

    cout << "Dime el codigo de una receta:";
    string c;
    cin >> c;

    cout << "La receta es " << r_all[c] << endl;

    //*************************************************************************
    //APARTADO 8
    //*************************************************************************

    cout << "Dime dos códigos de recetas para fusionar:";
    string code1, code2;
    cin >> code1 >> code2;

    //*************************************************************************
    //APARTADO 9 y 10
    //*************************************************************************

    while (r_all[code1].getPlato() != r_all[code2].getPlato())
    {
        cout << FRED("\nError. No se pueden fusionar las recetas indicadas. Han de tener el mismo número de plato. Introduzca unas nuevas: ");
        cin >> code1 >> code2;
    }

    pair<bool, string> rec1_corr = r_all[code1].correcta(all_ingre);
    pair<bool, string> rec2_corr = r_all[code2].correcta(all_ingre);

    if (rec1_corr.first && rec2_corr.first)
    {
        cout << "La receta fusionada es " << r_all[code1].Fusion(r_all[code2]) << endl;
    }
    else if (!rec1_corr.first)
    {
        cerr << FRED("La receta ") << code1 << FRED(" no es correcta. Contiene el ingrediente ") << rec1_corr.second << FRED(" que no existe en el fichero de ingredientes. ") << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cerr << FRED("La receta ") << code2 << FRED(" no es correcta. Contiene el ingrediente ") << rec2_corr.second << FRED(" que no existe en el fichero de ingredientes. ") << endl;
        exit(EXIT_FAILURE);
    }
}
