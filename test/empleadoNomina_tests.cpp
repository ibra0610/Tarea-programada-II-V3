#include <gtest/gtest.h>
#include <iostream> 
#include <sstream> 

#include "../src/empleadoNomina.h" 

using namespace std; 

namespace{
    TEST(empleadoNomina_Test, Test_constructor){
        EmpleadoNomina *empleado1 = new EmpleadoNomina(1,"Denis","Tyler", "denis_tyler@biz.com",1,0); 

        ostringstream salida{}; 
        salida<< *empleado1; 
        string actual = salida.str(); 

        delete empleado1; 

        EXPECT_EQ("1,Denis Tyler,NO TIENE SUPERVISOR,0",actual);
    }

    TEST(empleadoNomina_Test, Test_getNombre){
        EmpleadoNomina *empleado1 = new EmpleadoNomina(1,"Denis","Tyler", "denis_tyler@biz.com",1,0); 

        string salida = empleado1->getNombre();

        delete empleado1; 

        EXPECT_EQ("Denis Tyler",salida); 
    }

    TEST(empleadoNomina_Test, Test_asignePago){
        EmpleadoNomina *empleado1 = new EmpleadoNomina(1,"Denis","Tyler", "denis_tyler@biz.com",1,0);
        empleado1->asignePago(4278.91);


        ostringstream salida{};
        salida<< *empleado1; 
        string actual = salida.str();

        delete empleado1;

        EXPECT_EQ("1,Denis Tyler,NO TIENE SUPERVISOR,4278.91",actual);
    }

    TEST(empleadoNomina_Test, Test_asigneSupervisor){
        EmpleadoNomina *empleado1 = new EmpleadoNomina(2,"Clarissa","Parker","clarissa_parker@biz.com",1,1); 
        empleado1->asigneSupervisor("Denis Tyler");

        ostringstream salida{}; 
        salida<< *empleado1; 
        string actual = salida.str();
        delete empleado1;

        EXPECT_EQ("2,Clarissa Parker,Denis Tyler,0",actual);
    }
}