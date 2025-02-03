#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // Para sleep() en sistemas UNIX
// Para Windows, comenta la línea anterior y descomenta la siguiente:
// #include <windows.h>
/*Las reglas son concisas:
	•	Supervivencia: Una célula viva con dos o tres vecinos vivos continúa viviendo.
	•	Muerte: Una célula viva muere por soledad (menos de dos vecinos vivos) o por sobrepoblación (más de tres vecinos vivos).
	•	Nacimiento: Una célula muerta se vuelve viva si tiene exactamente tres vecinos vivos.
*/
// Prototipos de funciones
int **createBoard(int rows, int cols);
void freeBoard(int **board, int rows);
void initializeBoard(int **board, int rows, int cols);
void printBoard(int **board, int rows, int cols);
int countNeighbors(int **board, int rows, int cols, int i, int j);
void updateBoard(int **board, int rows, int cols);

int main() {
    int rows, cols, generations, delay;

    // Solicitar parámetros al usuario
    printf("Juego de la Vida de Conway\n");
    printf("---------------------------\n");
    printf("Ingrese el número de filas del tablero: ");
    scanf("%d", &rows);
    printf("Ingrese el número de columnas del tablero: ");
    scanf("%d", &cols);
    printf("Ingrese el número de generaciones a simular: ");
    scanf("%d", &generations);
    printf("Ingrese el retardo entre generaciones (en segundos): ");
    scanf("%d", &delay);

    // Inicializar semilla para números aleatorios
    srand(time(NULL));

    // Crear e inicializar el tablero
    int **board = createBoard(rows, cols);
    initializeBoard(board, rows, cols);

    // Bucle principal de simulación
    for (int gen = 0; gen < generations; gen++) {
        // Limpiar la consola:
        // En UNIX/Linux/macOS:
        system("clear");
        // En Windows, reemplaza la línea anterior por:
        // system("cls");

        printf("Generación %d\n", gen);
        printBoard(board, rows, cols);
        updateBoard(board, rows, cols);

        // Esperar el retardo especificado
        sleep(delay);  
        // En Windows, usa: Sleep(delay * 1000);
    }

    // Liberar memoria
    freeBoard(board, rows);

    return 0;
}

// Función para crear dinámicamente un tablero (matriz de enteros)
int **createBoard(int rows, int cols) {
    int **board = malloc(rows * sizeof(int *));
    if (!board) {
        fprintf(stderr, "Error al asignar memoria para las filas.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        board[i] = malloc(cols * sizeof(int));
        if (!board[i]) {
            fprintf(stderr, "Error al asignar memoria para la fila %d.\n", i);
            exit(EXIT_FAILURE);
        }
    }
    return board;
}

// Función para liberar la memoria del tablero
void freeBoard(int **board, int rows) {
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);
}

// Inicializa el tablero con valores aleatorios: 0 (muerta) o 1 (viva)
void initializeBoard(int **board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Imprime el tablero en la consola
void printBoard(int **board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Se utiliza 'O' para celda viva y un espacio en blanco para celda muerta
            printf("%c", board[i][j] ? 'O' : ' ');
        }
        printf("\n");
    }
}

// Cuenta los vecinos vivos (8 posiciones alrededor) de la celda (i, j)
int countNeighbors(int **board, int rows, int cols, int i, int j) {
    int count = 0;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue;  // No se cuenta la propia celda
            int ni = i + di;
            int nj = j + dj;
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                count += board[ni][nj];
            }
        }
    }
    return count;
}

// Actualiza el tablero aplicando las reglas de Conway
void updateBoard(int **board, int rows, int cols) {
    // Crear un tablero auxiliar para almacenar el nuevo estado
    int **newBoard = createBoard(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = countNeighbors(board, rows, cols, i, j);

            if (board[i][j] == 1) { // Celda viva
                // Regla de supervivencia: 2 o 3 vecinos vivos
                if (neighbors < 2 || neighbors > 3)
                    newBoard[i][j] = 0;  // Muere por soledad o sobrepoblación
                else
                    newBoard[i][j] = 1;  // Sobrevive
            } else { // Celda muerta
                // Regla de nacimiento: exactamente 3 vecinos vivos
                newBoard[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }

    // Copiar el nuevo estado al tablero original
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
    freeBoard(newBoard, rows);
}
