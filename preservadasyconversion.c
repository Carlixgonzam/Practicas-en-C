#include <stdio.h>

int main(){
    int a = 80;
    float f = 45.3;
    float suma = (float)a + f;

    printf("entero %i\n floatante %.2f\n double %.3f\n caracter %c\n",a,(float)a, (double)a, (char)a);
    return 0;
}