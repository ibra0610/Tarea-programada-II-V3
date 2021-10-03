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
    

    public: 
    Arbol(); 
    ~Arbol(); 
    void agregarEmpleado(int, Empleado *empleado, int);
    string deNombre(int id);
    void asignePago(int id, float pago);
    
    friend ostream& operator << (ostream &output, const Arbol &arbol); 
    friend istream& operator >> (istream &input, Arbol &arbol); 

}; 
#endif