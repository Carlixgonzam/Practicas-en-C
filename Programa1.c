/*Primer practica en el lenguaje de programacion C*/
#include <stdio.h>

int main(){
    int num1;
    int num2;
    int resultado;
    printf("Ingrese el primer valor\n");
    scanf("%d", &num1); //Se utiliza el scanf para leer el valor ingresado por el usuario
    printf("Ingrese el segundo valor\n");
    scanf("%d", &num2);
    resultado = num1 + num2;
    printf("El resultado es: %d\n", resultado);
    return 0; //Se utiliza para indicar que el programa se ejecuto correctamente

}
