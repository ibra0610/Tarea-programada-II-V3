#include "empleadoNomina.h" 
#include <fstream> 
#include <sstream>

EmpleadoNomina :: EmpleadoNomina(int _id_empleado, string _nombre, string _apellido, string _email, int _tipo_empleado, int _id_supervisor){
    this-> id_empleado = _id_empleado; 
    this-> nombre = _nombre; 
    this-> apellido = _apellido; 
    this-> email = _email; 
    this-> tipo_empleado = _tipo_empleado; 
    this-> id_supervisor = _id_supervisor; 
    this ->nombre_supervisor = "NO TIENE SUPERVISOR";
    this->pago_a_empleado =0; 
} 

ostream& EmpleadoNomina::serializar(ostream& output) const {
    output<< this -> id_empleado << "," << this->nombre;
    output << " " << this-> apellido << "," << this->nombre_supervisor; 
    output << "," << this->pago_a_empleado;

    return output;
 }



 