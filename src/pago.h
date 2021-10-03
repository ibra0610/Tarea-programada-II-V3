#ifndef PAGO_H 
#define PAGO_H 

#include "arbol.h"

class Pago{
    float subtotal;
    float total_impuestos; 
    float total;  
    float id_empleado_a_pagar; 
    float monto_a_pagar; 

    public: 
    Pago(); 
    void calcule_y_asignePago(Arbol *arbol);
    float deMontoAPagar();
    float deSubtotal(); 
    float deTotalImpuestos(); 
    float deTotal(); 

}; 

#endif