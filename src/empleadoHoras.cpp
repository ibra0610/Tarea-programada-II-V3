#include "empleadoHoras.h"
#include <iostream> 

EmpleadoHoras::EmpleadoHoras(int _id_empleado, string _nombre, string _apellido, string _email, int _tipo_empleado, int _id_supervisor, float _pago_por_hora){
    this-> id_empleado = _id_empleado; 
    this-> nombre = _nombre; 
    this-> apellido = _apellido; 
    this-> email = _email; 
    this-> tipo_empleado = _tipo_empleado; 
    this-> id_supervisor = _id_supervisor; 
    this-> pago_por_hora = _pago_por_hora; 

}

ostream& EmpleadoHoras::serializar(ostream& output) const {
    output<<"Empleado por horas (" <<this->id_empleado << "): "; 
    output << this-> nombre << " pago: " << this->pago_por_hora; 

    return output;
}