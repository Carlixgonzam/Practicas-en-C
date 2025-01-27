#include <stdio.h>

int main(){
    int casos;
    printf("Ingresa un numero\n");
    scanf("%i", &casos);
    switch (casos)
    {
        case 1:
        printf("Elegiste el primer caso\n");
        break;

        case 2:
        printf("Elegiste el segundo caso\n");
        break;

        case 3:
        printf("Elegiste el tercer caso\n");
        break;
    
    default:
    break;
    }
    return 0;
}