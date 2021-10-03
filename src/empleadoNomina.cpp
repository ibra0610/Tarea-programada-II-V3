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
    output << this-> apellido << "," << this->nombre_supervisor; 
    output << "," << this->pago_a_empleado;

    return output;
 }

// void EmpleadoNomina:: asignePago(int id_a_pagar){
//     ifstream nomina("Nomina.txt",ifstream::in); 

//     if(!nomina.is_open()){
//         cerr<< "Error leyendo archivo Nomina.txt" << endl;  
//     } 

//     string linea = ""; 
//     float monto=0;
//     int id_nomina =0;
//     float monto_bruto = 0;
//     float impuesto_unico= 0; 

//     while(getline(nomina,linea)){
//         istringstream stream(linea); 

//         linea = ""; 
//         monto =0;
//         id_nomina =0;
//         monto_bruto = 0;
//         impuesto_unico= 0; 

//         stream >> id_nomina >> monto_bruto; 

//         if(id_nomina==id_a_pagar){
//             impuesto_unico = monto_bruto * 7/100; 
//             total_impuestos +=impuesto_unico;
//             pago_a_empleado = monto_bruto - impuesto_unico;
//             subtotal+= pago_a_empleado;
//         }
        
//     }
//     nomina.close();

// }

 