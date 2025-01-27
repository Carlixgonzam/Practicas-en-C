#include <stdio.h>
/*
int main(){
    int arreglo[4] = {3,4,1,5};
    printf("%i", arreglo[2]); 

    return 0;
    } */

int main(){
    int sizeA;
    printf("Tamaño del arreglo\n");
    scanf("%i", &sizeA);
    int age[sizeA];
    for(int i = 0; i < sizeA; i++){
        printf("Ingresa el valor%i\n", i+1);
        scanf("%i", &age[i]);
    }
    printf("Los valores del arreglo son:\n");
    for(int i = 0; i < sizeA; i++){
        printf("%i-\n", age[i]);
    }
    return 0;
}
