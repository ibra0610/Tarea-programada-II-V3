#ifndef EMPLEADO_H 
#define EMPLEADO_H 

#include <iostream> 

using namespace std; 

class Empleado{
    protected: 
    int id_empleado, tipo_empleado, id_supervisor; 
    string nombre, apellido, email, nombre_supervisor;
    float pago_a_empleado;

    virtual ostream& serializar(ostream& out) const; 

    Empleado(){ }

    public: 
    ~Empleado(){}
    virtual string getNombre();
    virtual void asigneSupervisor(string nombreSup);
    virtual void asignePago(float nuevo_pago);
   
    friend ostream& operator << (ostream &output, const Empleado &empleado);
}; 

#endif