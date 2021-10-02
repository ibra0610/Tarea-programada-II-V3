#ifndef EMPLEADONOMINA_H 
#define EMPLEADONOMINA_H 

#include <iostream> 
#include "empleado.h" 

using namespace std; 

class EmpleadoNomina : public Empleado {
    float salario; 

    protected: 
    virtual ostream& serializar(ostream& out) const; 

    public: 
    EmpleadoNomina(int, string, string, string, int, int, float); 
    
}; 

#endif