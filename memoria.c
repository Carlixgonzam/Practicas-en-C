//Explorando la representación en memoria

//Declaro diferentes tipos de variables (short, int, char, punteros, arreglos)
//Imprime la memoria byte a byte de una variable

#include <stdio.h>

void print_memory(const void *ptr, size_t size, const char *desc) {
    unsigned char *byte = (unsigned char *) ptr;
    printf("\n%s (Dirección: %p, %lu bytes):\n", desc, ptr, size);
    for (size_t i = 0; i < size; i++) {
        printf("Byte %2lu: 0x%02X\n", i, byte[i]);
    }
    printf("\n");
}

int main() {
    //variables simples
    short s = -32749;   // 2 bytes
    int i = 1023;       // 4 bytes
    char c = 114;       // 1 byte
    int x = 7;          // 4 bytes

    // punteros
    short *ps = &s;
    int *pi = &i;
    char *pc = &c;
    int *px = &x;

    // arreglos
    short arr_short[2] = {20, -20}; // 4 bytes (2 shorts)
    int arr_int[2] = {32768, -32768}; // 8 bytes (2 ints)

    // Detectar Endianness
    int test = 1;
    char *ptest = (char *) &test;
    if (*ptest == 1)
        printf("Sistema: Little Endian\n");
    else
        printf("Sistema: Big Endian\n");

    // Imprimir memoria de cada variable
    print_memory(&s, sizeof(s), "short s (-32749)");
    print_memory(&i, sizeof(i), "int i (1023)");
    print_memory(&c, sizeof(c), "char c (114)");
    print_memory(&x, sizeof(x), "int x (7)");

    // Imprimir memoria de punteros
    print_memory(&ps, sizeof(ps), "Puntero a short *ps");
    print_memory(&pi, sizeof(pi), "Puntero a int *pi");
    print_memory(&pc, sizeof(pc), "Puntero a char *pc");
    print_memory(&px, sizeof(px), "Puntero a int *px");

    // Imprimir memoria de arreglos
    print_memory(arr_short, sizeof(arr_short), "Arreglo short arr_short[2] = {20, -20}");
    print_memory(arr_int, sizeof(arr_int), "Arreglo int arr_int[2] = {32768, -32768}");

    return 0;
}