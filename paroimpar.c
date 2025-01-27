#include <stdio.h>

int main(){
    int num;
    char resultado;
    printf("Ingrese el numero\n");
    scanf("%d", &num);
    if(num % 2== 0){
        printf("El numero es par\n");
    }else{
        printf("El numero es impar\n");
    }
    return 0;
}
