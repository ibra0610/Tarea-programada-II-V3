#include <gtest/gtest.h>
#include <iostream> 
#include <sstream> 

#include "../src/arbol.h" 
#include "../src/empleadoNomina.h"
#include "../src/empleadoHoras.h"

using namespace std; 

namespace{
    TEST(Arbol_Tests, Test_Constructor){
        Arbol *arbol = new Arbol(); 
        EmpleadoNomina *empleado = new EmpleadoNomina(1,"Javier","Cruz","ibrahimcruz06@gmail.com",1,0);
        arbol->agregarEmpleado(1,empleado,0);

        ostringstream salida {};
        salida << *arbol; 
        string actual = salida.str();

        delete arbol;

        EXPECT_EQ("1,Javier Cruz,NO TIENE SUPERVISOR,0", actual); 

    }

    TEST(Arbol_Tests, Test_Agregar_Empleado){
        Arbol *arbol = new Arbol(); 
        EmpleadoNomina *empleado1 = new EmpleadoNomina(1,"Javier","Cruz","ibrahimcruz06@gmail.com",1,0);
        EmpleadoHoras *empleado2 = new EmpleadoHoras(2, "Stephanie", "Palma", "sp@gmail.com",2,1);
        arbol->agregarEmpleado(1,empleado1,0); 
        arbol->agregarEmpleado(2,empleado2,1); 

        ostringstream  salida {}; 
        salida<<*arbol; 
        string actual = salida.str(); 

         delete arbol; 

         ostringstream salidaEsperada{}; 
         salidaEsperada << "1,Javier Cruz,NO TIENE SUPERVISOR,0" << endl;
         salidaEsperada << "2,Stephanie Palma,NO TIENE SUPERVISOR,0" << endl;
         string esperada = salidaEsperada.str(); 

         EXPECT_EQ(esperada,actual); 
          
    }
}