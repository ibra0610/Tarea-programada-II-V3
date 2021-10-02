#include "empleado.h" 
#include <iostream> 

ostream& Empleado::serializar(ostream& out)const {
    return out; 
} 

//ostream& operator << (ostream &output, const Empleado &empleado){
 //   return empleado.serializar(output);
//}

ostream& operator << (ostream &output, const Empleado &empleado){
    output << "PRUEBA:";
    output << empleado.nombre; 
    output << empleado.id_empleado;

    return empleado.serializar(output);
}