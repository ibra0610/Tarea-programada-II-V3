#include "empleadoNomina.h" 

EmpleadoNomina :: EmpleadoNomina(int _id_empleado, string _nombre, string _apellido, string _email, int _tipo_empleado, int _id_supervisor){
    this-> id_empleado = _id_empleado; 
    this-> nombre = _nombre; 
    this-> apellido = _apellido; 
    this-> email = _email; 
    this-> tipo_empleado = _tipo_empleado; 
    this-> id_supervisor = _id_supervisor; 
} 

ostream& EmpleadoNomina::serializar(ostream& output) const {
    output<< this -> nombre <<  this->apellido << ",";
    output << this-> id_empleado << "," << this->id_supervisor; 

    return output;
 }

 