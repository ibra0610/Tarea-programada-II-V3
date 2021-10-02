#include <iostream> 
#include <fstream> 
#include<sstream> 
#include <iomanip>

#include "arbol.h" 

using namespace std; 

int main(){
    ifstream lector("Personas.txt", ifstream::in); 

    if(!lector.is_open()){
        cerr<< "Error leyendo archivo Personas.txt" << endl; 
    }

    Arbol *arbol = new Arbol(); 

    lector>>*arbol; 

    ofstream archivo; 

    archivo.open("Reporte.csv", ios::out); 

    if(archivo.fail()){
        cout<< "No se pudo crear el archivo Reporte.csv"; 
    } 

    archivo<< "ID de empleado" << "," << "Nombre completo" << "," << "Nombre completo del supervisor" << "," << "Monto a pagar" << endl;
    archivo << *arbol << ","<<endl; 
    archivo<< "Subtotal: " <<","<< fixed << setw(11) << setprecision(6) << setfill(' ')<< arbol->deSubtotal() << ","<<endl; 
    archivo<< "Total de impuestos: " << "," << fixed << setw(11) << setprecision(6) << setfill(' ') << arbol->deTotalImpuestos() << ","  << endl; 
    archivo<< "Total: " << "," << fixed << setw(11) << setprecision(6) << setfill(' ')<< arbol->deTotal() << "," << endl; 
   

    archivo.close();

    delete arbol; 

    return 0; 
}