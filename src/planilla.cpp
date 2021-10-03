#include "planilla.h"
#include <iostream> 

Planilla::Planilla(int _id, Empleado* _empleado){
    this->id = _id; 
    this-> empleado = _empleado; 
} 

Planilla::~Planilla(){
    for(Planilla* empleado : this->subordinados){
        delete empleado;
    }
} 

void Planilla::agregueEmpleado(Planilla* nuevoEmpleado){
    this->subordinados.push_back(nuevoEmpleado); 
} 

string Planilla::deNombreEmpleado(){
    return this ->empleado->getNombre();
}

void Planilla::asignePago_a_Persona(float _nuevoPago){
    empleado->asignePago(_nuevoPago);
}



ostream& operator << (ostream &output, const Planilla &planilla){
    output << *(planilla.empleado);
    output << endl;

    for(Planilla* empleado : planilla.subordinados){
        output << *empleado;
    } 

    return output;
}

