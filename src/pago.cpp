#include <iostream> 
#include <fstream> 
#include "pago.h"
#include <sstream>

using namespace std; 

Pago::Pago(){
    this->id_empleado_a_pagar =0; 
    this ->monto_a_pagar =0; 
    this ->subtotal =0; 
    this-> total_impuestos =0 ;
    this -> total = 0; 
} 

void Pago::calcule_y_asignePago(Arbol *arbol){
    ifstream nomina("Nomina.txt", ifstream::in); 
    if(!nomina.is_open()){
        cerr<< "Error leyendo archivo Nomina.txt" << endl;  
    }
    string linea= ""; 
    float monto_bruto =0; 
    float impuesto_unico =0; 

    while(getline(nomina,linea)){
            istringstream stream(linea);

            linea ="";
            monto_a_pagar =0; 
            id_empleado_a_pagar=0;
            monto_bruto=0;
            impuesto_unico =0; 

            stream >> id_empleado_a_pagar >> monto_bruto; 

            impuesto_unico = monto_bruto * 7/100;
            total_impuestos+= impuesto_unico; 
            monto_a_pagar = monto_bruto - impuesto_unico; 

            subtotal+=monto_a_pagar; 

            arbol->asignePago(id_empleado_a_pagar, monto_a_pagar);
            
        
    }
    nomina.close(); 

    ifstream horas("HorasTrabajadas.txt",ifstream::in);
    if(!horas.is_open()){
        cerr<<"Error leyendo archivo HorasTrabajadas.txt" << endl; 
    } 
    int horas_a_pagar =0; 
    float monto_por_hora =0; 

    while(getline(horas,linea)){
            istringstream stream(linea); 
            linea =""; 
            id_empleado_a_pagar=0;
            monto_a_pagar =0;
            horas_a_pagar =0; 
            monto_por_hora =0; 

            stream >> id_empleado_a_pagar >> monto_por_hora >> horas_a_pagar;

            monto_a_pagar = monto_por_hora * horas_a_pagar; 

            subtotal+=monto_a_pagar; 

            arbol->asignePago(id_empleado_a_pagar, monto_a_pagar);
            

    }
    horas.close();

}

float Pago::deMontoAPagar(){
    return monto_a_pagar;
} 

float Pago::deSubtotal(){
    return subtotal; 
} 

float Pago::deTotal(){
    total = subtotal + total_impuestos;
    return total; 
}

float Pago::deTotalImpuestos(){
    return total_impuestos; 
}

