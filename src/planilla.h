#ifndef PLANILLA_H
#define PLANILLA_H

#include <vector>
#include <iostream> 
#include "empleado.h"; 

class Planilla{
    vector<Empleado *> empleados; 

    public: 
    Planilla(); 
    ~Planilla();

    void agregueEmpleado(Empleado *nuevoEmpleado) ;

    friend ostream& operator<< (ostream &o, const Planilla &planilla);
}; 
#endif