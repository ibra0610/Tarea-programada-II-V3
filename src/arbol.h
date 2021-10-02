#ifndef ARBOL_H
#define ARBOL_H 

#include <map> 
#include <iostream> 
#include "planilla.h" 

using namespace std; 

class Arbol{
    Planilla *jefe; 
    map<int, Planilla *> planilla; 

    public: 
    Arbol(); 
    ~Arbol(); 
    void agregarEmpleado(int, string, string, string, int, int);
    
    friend ostream& operator << (ostream &output, const Arbol &arbol); 
    friend istream& operator >> (istream &input, Arbol &arbol); 
    
}; 
#endif