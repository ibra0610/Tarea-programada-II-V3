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

float Empleado::de_Subtotal(){
    return this->subtotal; 
}

float Empleado::de_Impuestos(){
    return this ->total_impuestos; 
} 

float Empleado::de_total(){
    return this -> subtotal + this ->total_impuestos; 
}

void Empleado::asigneSupervisor(string nombreSupervisor){
    this->nombre_supervisor = nombreSupervisor;
}