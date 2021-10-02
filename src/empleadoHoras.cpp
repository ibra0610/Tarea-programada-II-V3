#include "empleadoHoras.h"
#include <iostream> 
#include <fstream> 
#include <sstream>

EmpleadoHoras::EmpleadoHoras(int _id_empleado, string _nombre, string _apellido, string _email, int _tipo_empleado, int _id_supervisor){
    this-> id_empleado = _id_empleado; 
    this-> nombre = _nombre; 
    this-> apellido = _apellido; 
    this-> email = _email; 
    this-> tipo_empleado = _tipo_empleado; 
    this-> id_supervisor = _id_supervisor; 
    this ->nombre_supervisor = "NO TIENE SUPERVISOR";
    this->pago_a_empleado =0; 
    this -> subtotal = 0; 
    this->total_impuestos =0;
}

ostream& EmpleadoHoras::serializar(ostream& output) const {
    output<< this -> id_empleado << "," << this->nombre;
    output << this-> apellido << "," << this->nombre_supervisor; 
    output << "," << this->pago_a_empleado;

    return output;
}

void EmpleadoHoras:: asignePago(int id_a_pagar){
    ifstream horasTrabajadas("HorasTrabajadas.txt",ifstream::in); 

    if(!horasTrabajadas.is_open()){
        cerr<< "Error leyendo archivo HorasTrabajadas.txt" << endl;  
    } 

    string linea = ""; 
    int id_horas =0;
    int horas_a_pagar =0; 
    float monto_por_hora =0; 

    while(getline(horasTrabajadas,linea)){
        istringstream stream(linea); 

        linea = ""; 
        id_horas =0; 
        horas_a_pagar =0; 
        monto_por_hora =0; 

        stream >> id_horas >> monto_por_hora >> horas_a_pagar; 

        if(id_horas==id_a_pagar){
            pago_a_empleado = monto_por_hora * horas_a_pagar; 
            subtotal+=pago_a_empleado;
        }
        
    }

}
