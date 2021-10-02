#ifndef EMPLEADO_H 
#define EMPLEADO_H 

#include <iostream> 

using namespace std; 

class Empleado{
    protected: 
    int id_empleado, tipo_empleado, id_supervisor; 
    string nombre, apellido, email, nombre_supervisor;
    float pago_a_empleado, subtotal, total_impuestos;

    virtual ostream& serializar(ostream& out) const; 

    Empleado(){ }

    public: 
    ~Empleado(){}
    virtual string getNombre();
    virtual void asigneSupervisor(string nombreSup);
    virtual float de_Subtotal(); 
    virtual float de_Impuestos(); 
    virtual float de_total();
    friend ostream& operator << (ostream &output, const Empleado &empleado);
}; 

#endif