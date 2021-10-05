#include <gtest/gtest.h>
#include <iostream>
#include <sstream> 

#include "../src/empleadoHoras.h"

using namespace std; 

namespace{
    TEST(empleadoHoras_Test, Test_constructor){
        EmpleadoHoras *empleado1 = new EmpleadoHoras(451,"Ryan", "Webster", "Ryan_Webster6612@hourpy.biz",2,214); 

        ostringstream salida{}; 
        salida<<*empleado1; 
        string actual = salida.str(); 

        delete empleado1; 

        EXPECT_EQ("451,Ryan Webster,NO TIENE SUPERVISOR,0",actual); 
    } 

    TEST(empleadoHoras_Test, Test_getNombre){
        EmpleadoHoras *empleado1 = new EmpleadoHoras(451,"Ryan", "Webster", "Ryan_Webster6612@hourpy.biz",2,214); 

        string salida = empleado1->getNombre();

        delete empleado1; 

        EXPECT_EQ("Ryan Webster",salida); 
    }

    TEST(empleadoHoras_Test, Test_asignePago){
        EmpleadoHoras *empleado1 = new EmpleadoHoras(451,"Ryan", "Webster", "Ryan_Webster6612@hourpy.biz",2,214);
        empleado1->asignePago(2324.3);

        ostringstream salida{};
        salida<< *empleado1; 
        string actual = salida.str();

        delete empleado1;

        EXPECT_EQ("451,Ryan Webster,NO TIENE SUPERVISOR,2324.3",actual);
    }

    TEST(empleadoNomina_Test, Test_asigneSupervisor){
        EmpleadoHoras *empleado1 = new EmpleadoHoras(451,"Ryan", "Webster", "Ryan_Webster6612@hourpy.biz",2,214); 
        empleado1->asigneSupervisor("Shay Matthews");

        ostringstream salida{}; 
        salida<< *empleado1; 
        string actual = salida.str();
        delete empleado1;

        EXPECT_EQ("451,Ryan Webster,Shay Matthews,0",actual);
    }

}