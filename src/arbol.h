#ifndef ARBOL_H
#define ARBOL_H 

#include <map> 
#include <iostream> 
#include "planilla.h" 
#include "empleado.h"

using namespace std; 

class Arbol{
    Planilla *raiz; 
    map<int, Planilla *> planilla; 
    float subtotal, total_impuestos, total; 

    public: 
    Arbol(); 
    ~Arbol(); 
    void agregarEmpleado(int, Empleado *empleado, int);
    string deNombre(int id);
    float deSubtotal();
    float deTotalImpuestos();
    float deTotal();
    friend ostream& operator << (ostream &output, const Arbol &arbol); 
    friend istream& operator >> (istream &input, Arbol &arbol); 

}; 
#endif