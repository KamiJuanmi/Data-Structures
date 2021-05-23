#ifndef RECETA_H
#define RECETA_H

#include <string>
#include "cstring"
#include <list>
#include <iostream>
#include "Instrucciones.h"
#include "Ingredientes.h"
#include "color.h"

using namespace std;

/**
 * @brief TDA Receta.
 * 
 * 
 * Una instancia del tipo de datos abstracto @c Receta es un conjunto de ingredientes
 * junto con los gramos de los mismos.
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

class Receta
{
private:
    /**
 * 
 * @page repReceta Representación del TDA Receta
 * 
 * @section invInvariante de representación
 * Un objeto @e a válido del TDA Receta debe cumplir:
 * - Debe de ser un conjunto no vacío de ingredientes.
 * - @c a.code ha de ser un código válido. 
 * - 0 <= @c a.calorias , @c a.hc , @c a.proteinas , @c a.grasas , @c a.fibra
 * 
 * @section faRecetas Función de abstracción.
 * Un objeto @e a del TDA Receta se define mediante una lista de pares de tipo string y unsigned int.
 * El string sería usado para almacenar el nombre del ingrediente y el unsigned int para almacenar la cantidad de gramos necesarios.
 * Además de la lista tambien hay dos string para el código y el nombre de la receta, un unsigned int para el número de plato y cinco float para almacenar el numero de calorías, proteínas, grasas, hidratos de carbono y fibra
 * Por otro lado, se incluye también una instancia del TDA Instrucciones que contiene las instrucciones a seguir para montar la receta.
 * 
 */
    string code;
    unsigned int plato;
    string nombre;
    list<pair<string, unsigned int>> ings;
    float calorias, hc, grasas, proteinas, fibra;
    Instrucciones inst;

public:
    Receta() = default;
    Receta(const Instrucciones &);
    /**
     * @brief Nombre de la receta 
     * 
     * @return Devuelve el nombre de la receta
     */
    string getNombre() const;
    /**
     * @brief Código de la receta
     * 
     * @return Devuelve el código de la receta
     */
    string getCode() const;
    /**
     * @brief Conjunto de todos los ingredientes.
     * 
     * @return Lista con todos los ingredientes que conforman la receta.
     */
    list<pair<string, unsigned int>> getIngredientes() const;
    /**
     * @brief Número de plato.
     * 
     * @return Devuelve el número de plato.
     */
    unsigned int getPlato() const;
    /**
     * @brief Cantidad de calorías.
     * 
     * @return Devuelve el número de calorias de la receta.
    */
    float getCalorias() const;
    /**
     * @brief Cantidad de hidratos de carbono. 
     * 
     * @return Devuelve la cantidad de hidratos de carbono
     */
    float getHC() const;
    /**
     * @brief Cantidad de grasas 
     * 
     * @return Devuelde la cantidad de grasas
     */
    float getGrasas() const;
    /**
     * @brief Cantidad de proteínas
     * 
     * @return Devuelde la cantidad de proteínas
     */
    float getProteinas() const;
    /**
     * @brief Cantidad de fibra
     * 
     * @return Devuelde la cantidad de fibra
     */
    float getFibra() const;
    /**
     * @brief Relación entre proteínas e hidratos de carbono.
     * 
     * @return Cociente entre las proteínas e hidratos de carbono.
     */
    float getRelacion() const;
    /**
     * @brief Instrucciones a seguir en la receta.
     * 
     * @return Objeto del TDA Instrucciones.
     */
    Instrucciones getInstrucciones() const;
    /**
     * @brief Número de ingredientes de la receta. 
     * 
     * @return Devuelve el número de ingredientes que componen la receta.
     */
    int ningredientes() const;
    /**
     * @brief Set del codigo de la receta
     * 
     * @param code código de la receta
     */
    void setCode(string code);
    /**
     *@brief Set del número de plato. 
     * 
     *@param plato número de plato.
     */
    void setPlato(unsigned int plato);
    /**
     * @brief Set del nombre de la receta.
     * 
     * @param nombre nombre de la receta. 
     */
    void setNombre(string nombre);
    /**
     * @brief Añade un ingrediente a la receta
     * 
     * @param ing ingrediente a añadir
     */
    void addIngrediente(pair<string, unsigned int> ing);
    /**
     *@brief Set de la cantidad de calorías de la receta. 
     * 
     * @param calorías cantidad de calorías de la receta.
     * @pre calorias >= 0
     */
    void setCalorias(float calorias);
    /**
     * @brief Set de la cantidad de hidratos de carbono de la receta.
     * 
     * @param hc cantidad de hidratos de carbono.
     * @pre hc >= 0
     */
    void setHC(float hc);
    /**
     * @brief Set de la cantidad de grasas. 
     * 
     * @param grasas cantidad de grasas.
     * @pre grasas >= 0
     */
    void setGrasas(float grasas);
    /**
     * @brief Set de la cantidad de proteinas de la receta.
     * 
     * @param proteinas cantidad de proteinas.
     * @pre proteinas>=0
     */
    void setProteinas(float proteinas);
    /**
     * @brief Set de la cantidad de fibra de la receta.
     * 
     * @param fibra cantidad de fibra.
     * @pre fibra>=0
     */
    void setFibra(float fibra);
    /**
     * @brief Fusión de dos recetas.
     * 
     * @param otra receta para fusionar.
     * @pre Ambas recetas han de ser válidas.
     * 
     * @return receta resultado de la fusión.
     */
    Receta Fusion(const Receta &otra);
    /**
     * @brief Inicializa las instrucciones de la receta.
     */
    void InicializaInstrucciones();
    /**
     * @brief Verifica si una receta es correcta.
     * 
     * @param ingre conjunto de todos los ingredientes.
     * 
     * @return par que contiene un booleano que indica si es correcta y, de no serlo, el string contiene el ingrediente que no es válido.
     */
    pair<bool, string> correcta(const Ingredientes &);

    class iterador
    {
    private:
        list<pair<string, unsigned int>>::iterator it;

    public:
        iterador &operator++()
        {
            this->it++;
            return *this;
        }

        iterador &operator--()
        {
            this->it--;
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

        pair<string, unsigned int> &operator*()
        {
            return *it;
        }

        iterador &operator=(const iterador &otro)
        {
            this->it = otro.it;
            return *this;
        }

        friend class Receta;
    };

    class const_iterador
    {
    private:
        list<pair<string, unsigned int>>::const_iterator it;

    public:
        const_iterador &operator++()
        {
            this->it++;
            return *this;
        }

        const_iterador &operator--()
        {
            this->it--;
            return *this;
        }

        bool operator==(const const_iterador &otro) const
        {
            return this->it == otro.it;
        }

        bool operator!=(const const_iterador &otro) const
        {
            return this->it != otro.it;
        }

        const pair<string, unsigned int> &operator*() const
        {
            return *it;
        }

        friend class Receta;
    };

    iterador begin()
    {
        iterador i;
        i.it = this->ings.begin();

        return i;
    }

    iterador end()
    {
        iterador i;
        i.it = this->ings.end();

        return i;
    }

    const_iterador cbegin() const
    {
        const_iterador i;
        i.it = this->ings.cbegin();

        return i;
    }

    const_iterador cend() const
    {
        const_iterador i;
        i.it = this->ings.cend();

        return i;
    }
};

istream &operator>>(istream &f, Receta &r);
ostream &operator<<(ostream &f, const Receta &r);

#endif
