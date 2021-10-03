#include "empleado.h" 
#include <iostream> 
#include <fstream> 
#include <sstream>

using namespace std; 

ostream& Empleado::serializar(ostream& out)const {
    return out; 
} 

ostream& operator << (ostream &output, const Empleado &empleado){
    return empleado.serializar(output);
}

string Empleado::getNombre(){
    return this->nombre + " " + this ->apellido;
}

void Empleado:: asignePago(float nuevo_pago){
    this->pago_a_empleado = nuevo_pago;
}


void Empleado::asigneSupervisor(string nombreSupervisor){
    this->nombre_supervisor = nombreSupervisor;
}