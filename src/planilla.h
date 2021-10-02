#ifndef PLANILLA_H
#define PLANILLA_H

#include <vector>
#include <iostream> 
#include "empleado.h" 

class Planilla{
    int id;
    Empleado* empleado;
    vector<Planilla *> subordinados; 

    protected:  

    public: 
    Planilla(int id, Empleado* empleado); 
    ~Planilla();

    void agregueEmpleado(Planilla *nuevoEmpleado) ;

    friend ostream& operator<< (ostream &o, const Planilla &planilla);
}; 
#endif