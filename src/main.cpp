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

    cout<< *arbol;

    delete arbol; 

    return 0; 
}