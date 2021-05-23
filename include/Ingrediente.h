#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <iostream>
using namespace std;

/**
 * @brief TDA Ingrediente.
 * 
 *
 * Una instancia del tipo de datos abstracto @c Ingrediente es una representación
 * de un ingrediente alimenticio mediante las calorías que aporta, el tipo de alimento y
 * los porcentajes de nutrientes esenciales.
 * 
 * 
 * Un ejemplo de su uso:
 * @include test_ingredientes.cpp
 * 
 * @author Juan Miguel Montañez Moreno
 * @author Adrián José Martínez Navarro
 * 
 * 
 * @date Octubre 2019
 */

class Ingrediente
{
private:
    /**
 * 
 * @page repIngrediente Representación del TDA Ingrediente
 * 
 * 
 * @section invIngrediente Invariante de representación
 * Un objeto @e a válido del TDA Ingrediente debe cumplir:
 *  - @c a.nombre ha de ser un nombre válido
 *  - 0 <= @c a.num_cal , @c a.p_hc , @c a.p_prot , @c a.p_gr , @c a.p_fib
 *  - @c a.tipo ha de ser un tipo de alimento válido 
 * 
 * @section faIngrediente Función de abstracción
 * Un objeto de @e a del TDA Ingrediente se representa mediante una cadena de caracteres que contiene el nombre, 
 * cinco flotantes que contienen los porcentajes de nutrientes esenciales y otra cadena de caracteres que contiene
 * el tipo de alimento. 
 * 
 */
    string nombre;
    float num_cal;
    float p_hc;
    float p_prot;
    float p_gr;
    float p_fib;
    string tipo;

public:
    /**
     * @brief Constructor 
     * 
     * @param nombre Nombre del ingrediente.
     * @param num_cal Numero de calorias que aporta cada 100 gramos.
     * @param p_hc Porcentaje de hidratos de carbono.
     * @param p_prot Porcentaje de proteinas.
     * @param p_gr Porcentaje de grasa.
     * @param p_fib Porcentaje de fibra.
     * @param tipo Tipo del ingrediente.
     * 
     * @pre 0 <= num_cal, p_hc, p_prot, p_gr, p_fib
     *
    */
    Ingrediente(string nombre = "Undefined", float num_cal = 0.0, float p_hc = 0.0, float p_prot = 0.0, float p_gr = 0.0, float p_fib = 0.0, string tipo = "");
    /**
     * @brief Nombre.
     * 
     * @return Devuelve el nombre del ingrediente.
    */
    string getNombre() const { return this->nombre; }
    /**
     * @brief Tipo.
     * 
     * @return Devuelte el tipo de ingrediente.
    */
    string getTipo() const { return this->tipo; }
    /**
     * @brief Num_Cal.
     * 
     * @return Devuelve el número de calorias aportadas por 100 gramos.
    */
    float getCalorias() const { return this->num_cal; }
    /**
     * @brief P_HC.
     * 
     * @return Devuelve el porcentaje de hidratos de carbono.
    */
    float getHc() const { return this->p_hc; }
    /**
     * @brief P_Prot.
     * 
     * @return Devuelve el porcentaje de proteinas.
    */
    float getProteinas() const { return this->p_prot; }
    /**
     * @brief P_Gras.
     * 
     * @return Devuelve el porcentaje de grasa.
    */
    float getGrasas() const { return this->p_gr; }
    /**
     * @brief P_Fibra.
     * 
     * @return Devuelve el porcentaje de fibra.
    */
    float getFibra() const { return this->p_fib; }
    /**
     * @brief Set del nombre.
     * 
     * @param nombre nombre del ingrediente.
    */
    void setNombre(string nombre);
    /**
     * @brief Set del número de calorias aportadas por 100 gramos.
     * 
     * @param cal número de calorias aportadas por 100 gramos.
     * 
     * @pre cal >= 0
    */
    void setCalorias(float cal);
    /**
     * @brief Set del porcentaje de hidratos de carbono.
     * 
     * @param hid porcentaje de hidratos de carbono.
     * 
     * @pre hid >= 0
    */
    void setHc(float hid);
    /**
     * @brief Set del porcentaje de proteinas.
     * 
     * @param prot porcentaje de proteinas.
     * 
     * @pre prot >= 0
     * 
    */
    void setProteinas(float prot);
    /**
     * @brief Set del porcentaje de grasa.
     * 
     * @param gras porcentaje de grasa.
     * 
     * @pre gras >= 0
    */
    void setGrasas(float gras);
    /**
     * @brief Set del porcentaje de fibra.
     * 
     * @param fib porcentaje de fibra.
     * 
     * @pre fib >= 0
    */
    void setFibra(float fib);
    /**
     * @brief Set del tipo.
     * 
     * @param tipo tipo de alimento.
    */
    void setTipo(string tipo);
};
/**
 * @brief Sobrecarga del operador de extracción de flujo.
 * 
 * @param f flujo a extraer.
 * @param uno objeto sobre el cual se va a escribir la información extraída.
 * 
 * @return referencia al flujo.
 */
istream &operator>>(istream &f, Ingrediente &uno);
/**
 * @brief Sobrecarga del operador de inserción de flujo.
 * 
 * @param f flujo a insertar.
 * @param uno objeto del cual se ba a obtener la información.
 * 
 * @return referencia al flujo.
 */
ostream &operator<<(ostream &f, const Ingrediente &uno);
#endif