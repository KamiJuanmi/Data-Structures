#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include <iostream>
#include <fstream>
#include "arbolbinario.h"
#include "Acciones.h"
#include <stack>

using namespace std;

typedef ArbolBinario<string> Arbol;

/**
 * @brief TDA Instrucciones.
 * 
 * 
 * Una instancia del tipo de datos abstracto @c Instrucciones es una secuencia de paso que deben darse
 * para cocinar una receta.
 * 
 * Un ejemplo de su uso:
 * @include cocinero_integral.cpp
 * 
 * @author Juan Miguel Montañez Moreno
 * @author Adrián José Martínez Navarro
 * 
 *  
 * @date Diciembre 2019
 * 
 */

class Instrucciones
{
private:
    /**
 * 
 * @page repInstrucciones Representación del TDA Instrucciones
 * 
 * @section invInstrucciones Invariante de representación
 * Un objeto @e a válido del TDA Instrucciones debe cumplir:
 * - @c a.datos ha de ser un arbol binario no nulo. 
 * - @c a.acc ha de ser una instancia válida del TDA Acciones
 * - @c a.ruta ha de ser una ruta válida en la que se encuentre la información de las instrucciones.
 * 
 * @section faInstrucciones Función de abstracción.
 * Un objeto @e a del TDA Instrucciones se define mediante un árbol binario que contiene los pasos a seguir para cocinar la receta,
 * una instancia estática del TDA Acciones que contiene todas las acciones disponibles y un string que contiene el path donde se encuentran 
 * todas las instrucciones
 * 
 */
    Arbol datos;
    static Acciones acc;
    static string ruta;

public:
    Instrucciones() = default;
    Instrucciones(string);
    Instrucciones(const Arbol &);
    /**
     * @brief Devuelve el árbol de acciones. 
     */
    Arbol getArbol() const;
    /**
     * @brief Inicializa las acciones. 
     * 
     * @param path ruta en la que se encuentra el archivo de datos de acciones.
     */
    static void InicializaAcciones(string path);
    /**
     * @brief Inicializa la ruta donde se encuentran las instrucciones. 
     * 
     * @param path ruta en la que se encuentra el directorio con las instrucciones.
     */
    static void InicializaRuta(string path);
    /**
     * @brief Sobrecarga del operador de asignacion. 
     * 
     * @param otra conjunto de instrucciones a asignar.
     */
    Instrucciones &operator=(const Instrucciones &);
    /**
     * @brief Recorrido en postorden. 
     * 
     * @param f flujo en el que se inserta la informacion del árbol.
     * @param r raiz del árbol
     */
    ostream &Postorden(ostream &, Arbol::nodo) const;
    /**
     * @brief Fusión de dos conjuntos de instrucciones. 
     * 
     * @param otras conjunto de instruciones a fusionar con el instanciado.
     * @pre Todos los conjuntos de instrucciones han de ser válidos.
     * 
     * @return Conjunto fusión.
     */
    Instrucciones Fusion(const Instrucciones &);
};

ostream &operator<<(ostream &f, const Instrucciones &);

#endif