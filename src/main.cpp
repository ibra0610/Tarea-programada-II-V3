#include <iostream> 
#include <fstream> 
#include<sstream> 

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

    archivo<< "Nombre" << "," << "ID empleado" << "," << "ID supervisor" << endl;
    archivo << *arbol << ","<<endl; 
   

    archivo.close();

    delete arbol; 

    return 0; 
}