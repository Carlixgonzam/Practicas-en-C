#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i;
    int *array;

    printf("Ingrese el número de elementos: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: número de elementos inválido.\n");
        return 1;
    }

    // Asignación dinámica de memoria usando malloc
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria.\n");
        return 1;
    }

    // Ingreso de datos en el array
    for (i = 0; i < n; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Error: entrada no válida.\n");
            free(array);  // Liberar memoria en caso de error
            return 1;
        }
    }

    // Impresión de los elementos ingresados
    printf("Los elementos ingresados son:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberación de la memoria asignada
    free(array);

    return 0;
}