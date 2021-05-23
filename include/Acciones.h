#ifndef ACCIONES_H
#define ACCIONES_H

#include <iostream>
#include <map>

using namespace std;

typedef map<string, unsigned char> Acc_Arid;

/**
 * @brief TDA Recetas.
 * 
 * 
 * Una instancia del tipo de datos abstracto @c Acciones es un diccionario de acciones y su aridad.
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

class Acciones
{
private:
    /**
 * 
 * @page repAcciones Representación del TDA Acciones
 * 
 * @section invAcciones Invariante de representación
 * Un objeto @e a válido del TDA Acciones debe cumplir:
 * - Debe de ser un conjunto no vacío de Acciones.
 * - La @c acción debe ser válida. 
 * - 0 < @c aridad para todas las acciones.
 * 
 * @section faAcciones Función de abstracción.
 * Un objeto @e a del TDA Acciones se define mediante un diccionario cuya key es un string y el valor es un unsigned char.
 * El string seria usado para almacenar el nombre de la acción y el usigned char para almacenar la aridad de dicha acción.
 * 
 */
    Acc_Arid datos;

public:
    Acciones() = default;
    Acciones(string ruta);
    /**
     * @brief Insertar en el diccionario una nueva acción y su aridad.
     * 
     * @param nuevo pair formado por la acción y su aridad.
     * 
     * @pre La acción ha de ser válida y su aridad > 0.
     */
    void insert(Acc_Arid::value_type nuevo);
    /**
     * @brief Instancia vacía.
     * 
     * @return Devuelve si el conjunto de acciones esta vacío o no.
     */
    bool empty() const;
    /**
     * @brief Sobrecarga del operador de indexación como l-value.
     * 
     * @param key nombre de la acción.
     * @pre La acción ha de ser válida.
     * 
     * @return Devuelve una referencia a la aridad de la acción que se ha pasado como parámetro.
     * 
     */
    Acc_Arid::mapped_type &operator[](const Acc_Arid::key_type &key);
    /**
     * @brief Sobrecarga del operador de indexación como r-value.
     * 
     * @param key nombre de la acción.
     * @pre La acción ha de ser válida.
     * 
     * @return Devuelve una referencia a la aridad de la acción que se ha pasado como parámetro.
     * 
     */
    const Acc_Arid::mapped_type &operator[](const Acc_Arid::key_type &key) const;

    class iterador
    {
    private:
        Acc_Arid::iterator it;

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
        Acc_Arid::value_type &operator*()
        {
            return *it;
        };
        iterador &operator=(const iterador &otro)
        {
            this->it = otro.it;
            return *this;
        };

        friend class Acciones;
    };

    class const_iterador
    {
    private:
        Acc_Arid::const_iterator it;

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

        const Acc_Arid::value_type &operator*() const
        {
            return *it;
        };

        bool operator!=(const const_iterador &otro) const
        {
            return it != otro.it;
        };

        friend class Acciones;
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

istream &operator>>(istream &f, Acciones &unas);

ostream &operator<<(ostream &f, const Acciones &unas);

#endif