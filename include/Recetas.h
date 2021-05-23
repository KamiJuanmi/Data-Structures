#ifndef RECETAS_H
#define RECETAS_H

#include "Receta.h"
#include <string>
#include <map>

using namespace std;

/**
 * @brief TDA Recetas.
 * 
 * 
 * Una instancia del tipo de datos abstracto @c Recetas es un conjunto de pares de
 * recetas y sus nombres.
 * 
 * Un ejemplo de su uso:
 * @include test_receta.cpp
 * 
 * @author Juan Miguel Montañez Moreno
 * @author Adrián José Martínez Navarro
 * 
 *  
 * @date Noviembre 2019
 * 
 */

class Recetas
{
private:
/**
 * 
 * @page repRecetas Representación del TDA Recetas
 * 
 * @section invInvariante de representación
 * Un objeto @e a válido del TDA Recetas debe cumplir:
 * - Debe de ser un conjunto no vacío del TDA Receta.
 * - @c a.string ha de ser un nombre de Receta válido.
 * 
 * @section faRecetas Función de abstracción.
 * Un objeto @e a del TDA Recetas se representa mediante un diccionario cuyos pares contienen el nombre de la receta
 * y la receta en si misma
 * 
 */
    map<string, Receta> datos;

public:
    Recetas() = default;
    /**
     * @brief Constructor de copia.
     * 
     */
    Recetas(const Recetas &otra);
    /**
     * @brief Número de recetas en el conjunto. 
     * 
     * @return Devuelve el número de recetas.
     */
    int size();
    /**
     * @brief Vacía el conjunto.
     */
    void clear();
    /**
     * @brief Número de calorias de las recetas.
     * 
     * @return Devuelve sumatoria de las calorias de las recetas.
     */
    float getCalorias() const;
    /**
     * @brief Relación de las recetas.
     * 
     * @return Devuelve sumatoria de las relaciones de las recetas.
     */
    float getRelacion() const;
    /**
     * @brief Número de proteínas de las recetas.
     * 
     * @return Devuelve sumatoria de las proteínas de las recetas.
     */
    float getProteinas() const;
    /**
     * @brief Número de hidratos de carbono de las recetas.
     * 
     * @return Devuelve sumatoria de los hidratos de carbono de las recetas.
     */
    float getHC() const;
    /**
     * @brief Borrar una receta según su código. 
     * 
     * @param code código de la receta.
     * 
     */
    void borrar(string code);
    /**
     * @brief Operador de asignación.
     * 
     * @param otra referencia constante de la receta a asignar.
     * 
     * @return Referencia al objeto instanciado.
     */
    Recetas &operator=(const Recetas &otra);
    /**
     * @brief Añade una receta
     * 
     * @param una par que contiene un código de receta y una receta.
     */
    void addReceta(const pair<string, Receta> &una);
    /**
     * @brief Sobrecarga del operador de indexación como r-value.
     * 
     * @param code código de la receta.
     * @pre El código ha de ser válido.
     * 
     * @return Devuelve una referencia constante a la receta cuyo código es el pasado como parámetro.
     */
    const Receta &operator[](string code) const;
    /**
     * @brief Sobrecarga del operador de indexación como l-value.
     * 
     * @param code código de la receta.
     * @pre El código ha de ser válido.
     * 
     * @return Devuelve una referencia a la receta cuyo código es el pasado como parámetro.
     * 
     */
    Receta &operator[](string code);

    class iterador
    {
    private:
        map<string, Receta>::iterator it;

    public:
        iterador &operator++()
        {
            it++;
            return *this;
        }
        iterador &operator--()
        {
            it--;
            return *this;
        }
        bool operator==(const iterador &otro) const
        {
            return this->it == otro.it;
        }

        bool operator!=(const iterador &otro) const
        {
            return this->it != otro.it;
        }

        iterador &operator=(const iterador &otro)
        {
            this->it = otro.it;
            return *this;
        }

        Receta &operator*()
        {
            return (*it).second;
        }

        friend class Recetas;
    };

    class const_iterador
    {
    private:
        map<string, Receta>::const_iterator it;

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

        const_iterador &operator=(const const_iterador &otro)
        {
            this->it = otro.it;
            return *this;
        }

        bool operator!=(const const_iterador &otro) const
        {
            return it != otro.it;
        };

        const Receta &operator*()
        {
            return (*it).second;
        };

        friend class Recetas;
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

istream &operator>>(istream &f, Recetas &una);
ostream &operator<<(ostream &f, const Recetas &una);

#endif
