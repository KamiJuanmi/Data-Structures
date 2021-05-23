#ifndef INGREDIENTES_H
#define INGREDIENTES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Ingrediente.h"

/**
 * @brief TDA Ingredientes.
 * 
 * 
 * Una instancia del tipo de datos abstracto @c Ingredientes es una colección ordenada de instancias
 * del TDA @c Ingrediente.
 * 
 * 
 * Un ejemplo de su uso:
 * @include test_ingredientes.cpp
 * 
 * @author Adrián José Martínez Navarro
 * @author Juan Miguel Montañez Moreno
 * 
 * @date Octubre 2019
 */

class Ingredientes
{

private:
    /**
 * 
 * @page repIngredientes Representación del TDA Ingredientes.
 * 
 * 
 * @section invIngredientes Invariante de representación.
 * Un objeto @e a válido del TDA Ingredientes debe cumplir:
 *  - Todos los ingredientes contenidos son válidos.
 *  - Se respetan los ordenes establecidos en el almacenamiento de los ingredientes.
 * 
 * 
 * @section faIngredientes Función de abstracción.
 * Un objeto @e a del TDA Ingredientes se define mediante dos objetos del TDA Vector Dinámico.
 * Uno de ellos contiene los ingredientes ordenados por nombre y el otro los índices del vector anterior
 * ordenados por tipo y, a igualdad de tipos, por nombres.
 */

    vector<Ingrediente> datos;
    vector<int> indices;

    /**
     * @brief Posición de busqueda/inserción según el nombre en el vector de ingredientes.
     * 
     * @param nombre nombre del ingrediente.
     * @param ini límite inferior de búsqueda.
     * @param fin límite superior de búsqueda.
     * 
     * @pre 0 <= @e ini <= @e fin < número de ingredientes
     * 
     * @return Par que incluye un booleano y un entero. El booleano indica si está ya insertado y el entero la posición.
     */
    pair<int, bool> getPos(string nombre, int ini, int fin) const;
    /**
     * @brief Posición de busqueda/inserción según el indice en el vector de ingredientes.
     * 
     * @param index indice del ingrediente en el vector de ingredientes.
     * @param ini límite inferior de búsqueda.
     * @param fin límite superior de búsqueda.
     * 
     * @pre 0 <= @e ini <= @e fin < número de ingredientes
     * 
     * @return Entero que indica la posición en el vector de índices.
     */
    int getPos(int index, int ini, int fin) const;

public:
    /**
     * @brief Número de ingredientes.
     * 
     * @return Devuelve el número de ingredientes.
     */
    int size();
    /**
     * @brief Busqueda de ingrediente según su nombre.
     * 
     * @param nombre nombre del ingrediente a buscar.
     * 
     * @pre @e nombre ha de ser un nombre válido.
     * 
     * @return Ingrediente cuyo nombre es el parámetro.
     */
    Ingrediente get(string nombre) const;
    /**
     * @brief Busqueda de ingrediente segun un valor @e i.
     * 
     * @param i posicion en la que se encuentra el ingrediente en el vector de ingredientes.
     * 
     * @pre 0 <= @e i < numero total de ingredientes.
     * 
     * @return Ingrediente encontrado en la posicion i en el vector de ingredientes. 
     */
    Ingrediente get(int i) const;

    /**
     * @brief Insercion del ingrediente @e ing respetando ambos ordenes.
     * 
     * @param ing ingrediente que se desea insertar.
     * 
     * @pre @e ing debe ser un ingrediente valido.
     */
    void insertar(const Ingrediente &ing);

    /**
     * @brief Se elimina del vector de ingredientes el ingrediente que tenga como nombre @e nombre;
     * 
     * @param nombre nombre del ingrediente que se desea borrar.
     * 
     * @pre @e nombre debe ser un nombre valido.
     * 
     */
    void borrar(string nombre);
    /**
     * @brief Imprimir ingredientes ordenados por tipo.
     * 
     * @param f flujo en el que se imprimen los ingredientes.
     */
    void ImprimirPorTipo(ostream &f) const;
    /**
     * @brief Ingredientes de un tipo dado.
     * 
     * @param tipo tipo de los ingredientes a obtener.
     * 
     * @pre @e tipo ha de ser un tipo válido.
     * 
     * @return Instancia del TDA Ingredientes con los ingredientes de tipo @e tipo
     */
    Ingredientes getIngredienteTipo(string tipo) const;
    /**
     * @brief Todos los tipos de los alimentos.
     * 
     * @return Instancia del TDA Vector con los tipos de los alimentos.
     */

    vector<string> getTipos() const;
    /**
     * @brief Sobrecarga del operador de indexacion como r-value
     * 
     * @param i posición del vector a indexar.
     * @pre 0 <= @e i < numero total de ingredientes
     * 
     * @return elemento i-ésimo del vector de ingredientes.
     * 
     */
    Ingrediente operator[](int i) const;
    /**
     * @brief Sobrecarga del operador de indexación como l-value
     * 
     * @param i posición del vector a indexar.
     * @pre 0 <= @e i < número total de ingredientes
     * 
     * @return referencia al elemento i-ésimo del vector de ingredientes.
     * 
     */
    Ingrediente &operator[](int i);
    /**
     * @brief Ingredientes
     * 
     * @return Instancia del TDA Vector con los ingredientes del objeto instanciado.
     */
    vector<Ingrediente> getIngredientes() const;

    class iterador
    {
    private:
        vector<Ingrediente>::iterator it;

    public:
        iterador &operator++()
        {
            it++;
            return *this;
        };
        iterador &operator--()
        {
            it--;
            return *this;
        };
        bool operator==(const iterador &otro) const
        {
            return it == otro.it;
        };
        bool operator!=(const iterador &otro) const
        {
            return it != otro.it;
        };
        Ingrediente &operator*()
        {
            return *it;
        };
        iterador &operator=(const iterador &otro)
        {
            this->it = otro.it;
            return *this;
        };

        friend class Ingredientes;
    };

    class const_iterador
    {
    private:
        vector<Ingrediente>::const_iterator it;

    public:
        const_iterador &operator++()
        {
            it++;
            return *this;
        };

        const_iterador &operator--()
        {
            it--;
            return *this;
        };

        bool operator==(const const_iterador &otro) const
        {
            return it == otro.it;
        };

        const Ingrediente &operator*() const
        {
            return *it;
        };

        bool operator!=(const const_iterador &otro) const
        {
            return it != otro.it;
        };

        friend class Ingredientes;
    };

    iterador begin()
    {
        iterador i;
        i.it = datos.begin();

        return i;
    };

    iterador end()
    {
        iterador i;
        i.it = datos.end();

        return i;
    };

    const_iterador cbegin() const
    {
        const_iterador i;
        i.it = datos.cbegin();

        return i;
    };

    const_iterador cend() const
    {
        const_iterador i;
        i.it = datos.cend();

        return i;
    };
};

ostream &operator<<(ostream &f, const Ingredientes &ing);
istream &operator>>(istream &f, Ingredientes &ing);

#endif