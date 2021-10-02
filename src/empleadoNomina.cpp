#include "empleadoNomina.h" 

EmpleadoNomina :: EmpleadoNomina(int _id_empleado, string _nombre, string _apellido, string _email, int _tipo_empleado, int _id_supervisor, float _salario){
    this-> id_empleado = _id_empleado; 
    this-> nombre = _nombre; 
    this-> apellido = _apellido; 
    this-> email = _email; 
    this-> tipo_empleado = _tipo_empleado; 
    this-> id_supervisor = _id_supervisor; 
    this-> salario = _salario; 
} 

ostream& EmpleadoNomina::serializar(ostream& output) const {
    output<< "Empleado nomina (" << this->id_empleado << "): "; 
    output << this-> nombre << " salario: " << this->salario; 

    return output;
 }