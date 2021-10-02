#include "planilla.h"
#include <iostream> 

Planilla::Planilla(){

} 

Planilla::~Planilla(){
    for(Empleado* empleado : this->empleados){
        delete empleado;
    }
} 

void Planilla::agregueEmpleado(Empleado* nuevoEmpleado){
    this->empleados.push_back(nuevoEmpleado); 
} 

ostream& operator << (ostream &output, const Planilla &planilla){
    output << "Planilla" << endl; 
    output << "Cantidad de empleados: " << planilla.empleados.size() << endl; 

    for(Empleado* empleado : planilla.empleados){
        output << *empleado << endl;
    } 

    return output;
}