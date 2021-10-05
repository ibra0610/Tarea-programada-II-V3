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
        EmpleadoNomina *empleado = new EmpleadoNomina(1,"Denis","Tyler","denis_tyler@biz.com",1,0);
        arbol->agregarEmpleado(1,empleado,0); 

        ostringstream salida {};
        salida << *arbol; 
        string actual = salida.str();

        delete empleado;
        delete arbol;

        EXPECT_EQ("1,Denis Tyler,NO TIENE SUPERVISOR,0\n", actual); 

    }

    TEST(Arbol_Tests, Test_Agregar_Empleado){
        Arbol *arbol = new Arbol(); 
        EmpleadoNomina *empleado1 = new EmpleadoNomina(1,"Denis","Tyler","denis_tyler@biz.com",1,0);
        EmpleadoHoras *empleado2 = new EmpleadoHoras(2,"Clarissa","Parker","clarissa_parker@biz.com",1,1);
            
        arbol->agregarEmpleado(1,empleado1,0); 
        arbol->agregarEmpleado(2,empleado2,1); 

        empleado2->asigneSupervisor(arbol->deNombre(1));

        ostringstream  salida {}; 
        salida<<*arbol; 
        string actual = salida.str(); 

         delete arbol; 
         delete empleado1;
         delete empleado2;
         

         ostringstream salidaEsperada{}; 
         salidaEsperada << "1,Denis Tyler,NO TIENE SUPERVISOR,0\n";
         salidaEsperada << "2,Clarissa Parker,Denis Tyler,0" << endl;
         string esperada = salidaEsperada.str(); 

         EXPECT_EQ(esperada,actual); 
          
    }

    TEST(Arbol_Tests, Test_Agregar_Empleados_UnNivel){
        Arbol *arbol = new Arbol(); 
        EmpleadoNomina *empleado1 = new EmpleadoNomina(1,"Denis", "Tyler","denis_tyler@biz.com",1,0);
        EmpleadoNomina *empleado2 = new EmpleadoNomina(2,"Clarissa","Parker","clarissa_parker@biz.com",1,1);
        EmpleadoNomina *empleado3 = new EmpleadoNomina(3,"Harmony","Rycroft","harmony_rycroft@biz.com",1,1);
            

        arbol->agregarEmpleado(1,empleado1,0); 
        arbol->agregarEmpleado(2,empleado2,1); 
        arbol->agregarEmpleado(3,empleado3,1); 

        empleado2->asigneSupervisor(arbol->deNombre(1));
        empleado3->asigneSupervisor(arbol->deNombre(1));
       

        ostringstream salida {}; 
        salida << *arbol; 
        string actual = salida.str(); 

        delete empleado1; 
        delete empleado2; 
        delete empleado3;
        delete arbol; 
        

        ostringstream salidaesperada {}; 
        salidaesperada << "1,Denis Tyler,NO TIENE SUPERVISOR,0\n"; 
        salidaesperada << "2,Clarissa Parker,Denis Tyler,0\n"; 
        salidaesperada << "3,Harmony Rycroft,Denis Tyler,0" << endl;
        string esperada = salidaesperada.str();

        EXPECT_EQ(esperada, actual); 

    }

    TEST(Arbol_Tests, Test_Agregar_Empleados_DosNiveles){
         Arbol *arbol = new Arbol();
         EmpleadoNomina *empleado1 = new EmpleadoNomina(1,"Denis", "Tyler","denis_tyler@biz.com",1,0);
         EmpleadoNomina *empleado2 = new EmpleadoNomina(2,"Clarissa","Parker","clarissa_parker@biz.com",1,1);
         EmpleadoNomina *empleado3 = new EmpleadoNomina(3,"Harmony","Rycroft","harmony_rycroft@biz.com",1,1);
         EmpleadoNomina *empleado4 = new EmpleadoNomina(6,"Boris","Wallace", "boris_wallace@biz.com",1,2); 
         EmpleadoNomina *empleado5 = new EmpleadoNomina(9,"Dani","James", "dani_james@biz.com",1,3); 

         arbol->agregarEmpleado(1,empleado1,0);
         arbol->agregarEmpleado(2,empleado2,1); 
         arbol->agregarEmpleado(3,empleado3,1); 
         arbol->agregarEmpleado(6,empleado4,2);
         arbol->agregarEmpleado(9,empleado5,3); 

         empleado2->asigneSupervisor(arbol->deNombre(1));
         empleado3->asigneSupervisor(arbol->deNombre(1));
         empleado4->asigneSupervisor(arbol->deNombre(2));
         empleado5->asigneSupervisor(arbol->deNombre(3));

         ostringstream salida {}; 
         salida << *arbol; 
         string actual = salida.str(); 

         delete empleado1; 
         delete empleado2; 
         delete empleado3; 
         delete empleado4; 
         delete empleado5; 
         delete arbol; 


         ostringstream salidaEsperada {}; 
        
         salidaEsperada << "1,Denis Tyler,NO TIENE SUPERVISOR,0\n";
         salidaEsperada << "2,Clarissa Parker,Denis Tyler,0\n"; 
         salidaEsperada << "6,Boris Wallace,Clarissa Parker,0\n";
         salidaEsperada << "3,Harmony Rycroft,Denis Tyler,0\n";
         salidaEsperada << "9,Dani James,Harmony Rycroft,0" << endl;
    
         
         string esperada = salidaEsperada.str(); 

         EXPECT_EQ(esperada,actual); 

    }

    TEST(Arbol_Tests, Test_Lectura_Stream){
        ostringstream streamGen {}; 
        streamGen << "1 Denis Tyler denis_tyler@biz.com 1" << endl; 
        streamGen << "2 Clarissa Parker clarissa_parker@biz.com 1 1" << endl;
        string entradaEj = streamGen.str(); 

        istringstream streamEntrada {entradaEj};
        Arbol *arbol = new Arbol(); 
        streamEntrada >> *arbol;
     


        ostringstream streamSalida {}; 
        streamSalida << *arbol; 
        string actual = streamSalida.str(); 

        delete arbol; 
  
        ostringstream streamSalidaEsperada {}; 
        streamSalidaEsperada << "1,Denis Tyler,NO TIENE SUPERVISOR,0\n"; 
        streamSalidaEsperada << "2,Clarissa Parker,Denis Tyler,0" << endl;
        string esperada = streamSalidaEsperada.str(); 

        EXPECT_EQ(esperada,actual); 
    }

}