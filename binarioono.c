/*Codigo para hallar los numeros binarios de un numero*/

#include <stdio.h>
int main(){
    int num;
    int resultado;
    printf("Ingrese numero\n");
    scanf("%d", &num);
    while(num > 0){
        printf("%d", num % 2);
        num /= 2;
    }
    return 0;
}