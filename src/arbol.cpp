#include <map>
#include <iostream> 
#include <sstream>

#include "arbol.h"
#include "empleado.h"
#include "empleadoHoras.h"
#include "empleadoNomina.h" 
#include "planilla.h"

using namespace std; 

Arbol::Arbol(){
    this -> raiz = nullptr; 
    this->subtotal = 0;
    this->total_impuestos =0; 
    this ->total =0;  
} 

Arbol:: ~Arbol(){
    if(this->raiz!=nullptr){
        delete this->raiz; 
    }
} 

void Arbol::agregarEmpleado(int _id_empleado, Empleado* _empleado, int _id_supervisor){
    Planilla *trabajador = new Planilla(_id_empleado, _empleado); 

    if(_id_supervisor==0){
        this->raiz = trabajador;
    }else{
        Planilla *trabajadorJefe = this->planilla.at(_id_supervisor);
        trabajadorJefe->agregueEmpleado(trabajador);
    }
    
        
    this->planilla.insert(pair<int, Planilla *> (_id_empleado,trabajador)); 
        
}

string Arbol::deNombre(int _id){
    return this->planilla.at(_id)->deNombreEmpleado();
}

float Arbol::deSubtotal(){
    return this->subtotal;
}

float Arbol::deTotalImpuestos(){
    return this->total_impuestos;
}

float Arbol::deTotal(){
    return this->total;
}

ostream& operator << (ostream &output, const Arbol &arbol){
    Planilla* raiz = arbol.raiz; 
    output << *(raiz); 

    return output;
}

istream& operator >> (istream &input, Arbol &arbol){
    string hilera = ""; 
    int id,tipo,supervisor; 
    string nombre,apellido,email;

    while(getline(input,hilera)){
        id =0; 
        tipo = 0; 
        supervisor =0; 
        nombre = ""; 
        apellido =""; 
        email=""; 

        istringstream stream (hilera); 
        stream >> id >> nombre >> apellido >> email >> tipo >> supervisor;

        if(tipo==1){
            EmpleadoNomina *empleadoNomina = new EmpleadoNomina(id,nombre,apellido,email,tipo,supervisor); 
            empleadoNomina->asignePago(id);
            arbol.subtotal += empleadoNomina->de_Subtotal();
            arbol.total_impuestos += empleadoNomina->de_Impuestos();
            arbol.total+=empleadoNomina->de_total();

            if(supervisor!=0){
                empleadoNomina->asigneSupervisor(arbol.deNombre(supervisor));
            }
            arbol.agregarEmpleado(id, empleadoNomina, supervisor);
        }else{
            EmpleadoHoras *empleadoHoras = new EmpleadoHoras(id,nombre,apellido,email,tipo,supervisor); 
            empleadoHoras->asignePago(id);
            arbol.subtotal += empleadoHoras->de_Subtotal();
            arbol.total_impuestos += empleadoHoras->de_Impuestos();
            arbol.total+=empleadoHoras->de_total();
            if(supervisor!=0){
                empleadoHoras->asigneSupervisor(arbol.deNombre(supervisor));
            }
            arbol.agregarEmpleado(id,empleadoHoras,supervisor);
        }

        
    }
    return input;
}


