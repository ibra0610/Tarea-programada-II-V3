#ifndef EMPLEADO_H 
#define EMPLEADO_H 

#include <iostream> 

using namespace std; 

class Empleado{
    protected: 
    int id_empleado, tipo_empleado, id_supervisor; 
    string nombre, apellido, email;

    virtual ostream& serializar(ostream& out) const; 

    Empleado(){ }

    public: 
    ~Empleado(){}

    friend ostream& operator << (ostream &output, const Empleado &empleado);
}; 

#endif