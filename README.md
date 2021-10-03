# Tarea-programada-II-V3
Programacion 2 grupo 2, Tarea programada II Javier Cruz C02517

El programa se compila y se ejecuta con main.cpp. 

En este caso tiene la clase planilla, la cual actúa como los "nodos" del arbol. 
En el arbol se procesa el archivo Personas.txt, en este caso conforme va procesando el archivo,
va asignando el nombre del supervisor de cada empleado y añade el empleado al árbol. 

Se podía haber creado un método para leer el archivo Nomina.txt en la clase empleadoNomina y otro
en la clase empleadoHoras para leer HorasTrabajadas.txt y de esta forma ir asignando el pago a cada 
empleado, pero este método requería leer cada archivo desde cero cada vez que se asignaba el pago a cada persona. 
Es por esto se crea la clase Pago, la cual recibe un árbol ya creado y lee ambos archivos una sola vez, al terminar cada
línea, busca el empleado en el árbol y le asigna el salario. Esta clase también maneja el subtotal, total de impuestos, y total 
general. 

Al finalizar, el programa crea un archivo llamado Reporte.csv con la información de cada empleado así como un resumen al final del
subtotal, total de impuestos y total general. 
