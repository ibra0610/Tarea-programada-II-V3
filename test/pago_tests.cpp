#include <gtest/gtest.h>
#include <iostream> 
#include <sstream> 
#include <fstream>

#include "../src/arbol.h"
#include "../src/pago.h" 

using namespace std; 

namespace{
    TEST(pago_Test, Test_deSubtotal){
        Pago *pago = new Pago(); 
        ifstream lector("Personas.txt", ifstream::in); 

        if(!lector.is_open()){
            cerr<< "Error leyendo archivo Personas.txt" << endl; 
        }

        Arbol *arbol = new Arbol(); 

        lector>>*arbol; 

        pago->calcule_y_asignePago(arbol);

        float actual = pago->deSubtotal(); 

        delete pago; 
        delete arbol; 

        EXPECT_FLOAT_EQ(1955351.375, actual);
    }

    TEST(pago_Test, Test_deTotal){
        Pago *pago = new Pago(); 
        ifstream lector("Personas.txt", ifstream::in); 

        if(!lector.is_open()){
            cerr<< "Error leyendo archivo Personas.txt" << endl; 
        }

        Arbol *arbol = new Arbol(); 

        lector>>*arbol; 

        pago->calcule_y_asignePago(arbol);

        float actual = pago->deTotal(); 

        delete pago; 
        delete arbol; 

        EXPECT_FLOAT_EQ(2075951.875, actual);
    }

    TEST(pago_Test, Test_deTotalImpuestos){
        Pago *pago = new Pago(); 
        ifstream lector("Personas.txt", ifstream::in); 

        if(!lector.is_open()){
            cerr<< "Error leyendo archivo Personas.txt" << endl; 
        }

        Arbol *arbol = new Arbol(); 

        lector>>*arbol; 

        pago->calcule_y_asignePago(arbol);

        float actual = pago->deTotalImpuestos(); 

        delete pago; 
        delete arbol; 

        EXPECT_FLOAT_EQ(120600.539062, actual);
    }
}