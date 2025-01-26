/*Directivas del preprocesador*/
#include <stdio.h> //encabezados de la biblioteca
//Librerias y macros
/*Include y el nombre del archivo*/
/*#include "nombre del archivo"*/
/*#define crea constantes simbolicas y macros*/
#define CUBO(a) a*a*a
#define PI 3.14159

int main(){
    int suma;
    int a = 3;
    suma = PI + 3;
    printf("%i", suma); //el %i es para imprimir un entero
    printf("%i\n", CUBO(a));
    return 0;

}

//Se utiliza el comando gcc directivaspreprocesador.c -o directivaspreprocesador para compilar el programa
