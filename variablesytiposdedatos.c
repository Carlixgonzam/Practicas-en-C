#include <stdio.h>
int main(){
    char C = 'y'; //tamaño de 1 byte 0...255
    int a = 20; //2 bytes -32768 ... 32767
    short e = -1; //2 bytes -128 ... 127
    unsigned int u = 25; //2 bytes 0 ... 65535
    long l = 5932; //4 bytes -2147483648 ... 2147483647
    float f = 72.523; //4 bytes
    double d = 1234.3424; //Tamaño de 8 bytes 
    printf("%c", C); //Imprimimos un caracter
    return 0;
}
