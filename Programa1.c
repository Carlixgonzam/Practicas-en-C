/*Primer practica en el lenguaje de programacion C*/
#include <stdio.h>

int main(){
    int num1;
    int num2;
    int resultado;
    int a = 5;
    int b = 10;
    printf("Ingrese el primer valor\n");
    scanf("%d", &num1); //Se utiliza el scanf para leer el valor ingresado por el usuario
    printf("Ingrese el segundo valor\n");
    scanf("%d", &num2);
    resultado = a*(num1 + num2) + b*(b+num2);
    printf("El resultado es: %d\n", resultado);
    return 0; //Se utiliza para indicar que el programa se ejecuto correctamente

}

//Se utiliza el comando gcc Programa1.c -o Programa1 para compilar el programa
//Se utiliza el comando ./Programa1 para ejecutar el programa
//Se utiliza el comando rm Programa1 para eliminar el programa
//Se utiliza el comando ls para ver los archivos en la carpeta
//Se utiliza el comando clear para limpiar la terminal
//Se utiliza el comando nano Programa1.c para editar el programa
//Se utiliza el comando gcc -Wall Programa1.c -o Programa1 para compilar el programa con advertencias
//Se utiliza el comando gcc -g Programa1.c -o Programa1 para compilar el programa con informacion de depuracion
//Se utiliza el comando gdb Programa1 para depurar el programa

