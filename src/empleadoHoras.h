#ifndef EMPLEADOHORAS_H 
#define EMPLEADOHORAS_H 

#include <iostream> 
#include "empleado.h" 

using namespace std; 

class EmpleadoHoras : public Empleado {
    

    protected: 
    virtual ostream& serializar (ostream& out) const; 

    public: 
    
    EmpleadoHoras(int, string, string, string, int, int);

}; 

#endif