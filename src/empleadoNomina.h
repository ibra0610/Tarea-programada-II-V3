#ifndef EMPLEADONOMINA_H 
#define EMPLEADONOMINA_H 

#include <iostream> 
#include "empleado.h" 

using namespace std; 

class EmpleadoNomina : public Empleado {
    

    protected: 
    virtual ostream& serializar(ostream& out) const; 

    public: 
    virtual void asignePago(int id_a_pagar);
    EmpleadoNomina(int, string, string, string, int, int); 

}; 

#endif