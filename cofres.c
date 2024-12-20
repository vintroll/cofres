
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
/*
    *%d:  entero tipo:int
    %u: entero sin singno tipo:unsigned
    %f: entero flotante tipo:float
    %lf: entero flotante doble (double float) tipo:double float
    %c: un caracter tipo: char
    %s: cadena de caracteres sin incluir espacios, tipo: char[]
    %x: hexadecimal
    %o: octal
    %p: direccion de memoria
     */
#define TIPO char 
#define LECTURA "%d"
#define ESCRITURA "%d"
void ***matriz = NULL;

struct  inventario{
    void ***chest;
    int space; 
};

//iniciar matriz
void ***inventariocustome(int filas, int columnas) {
    if (filas <= 0 || columnas <= 0) {
        return NULL;
    }

    // asignar mem filas
    matriz = malloc(filas * sizeof(void **));
    if (matriz == NULL) {
        return NULL;
    }

    //mem columnas y elementos "cambiar tipo del elemento"
    for (int i = 0; i < filas; ++i) {
        matriz[i] = malloc(columnas * sizeof(void *));
        if (matriz[i] == NULL) {
            //liberar memoria error
            for (int k = 0; k < i; ++k) {
                free(matriz[k]);
            }
            free(matriz);
            return NULL;
        }

        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = malloc(sizeof(TIPO));
            if (matriz[i][j] == NULL) {
                //liberar memoria error
                for (int k = 0; k <= i; ++k) {
                    for (int l = 0; l < (k < i ? columnas : j); ++l) {
                        free(matriz[k][l]);
                    }
                    free(matriz[k]);
                }
                free(matriz);
                return NULL;    
            }
            
            if(i !=0) {
                *(TIPO *)matriz[i][j] = 0;
            }else {
                *(TIPO *)matriz[i][j] = j+1;
            }
            
        }
    }

    return matriz;
}


// liberar matriz
void liberarmatriz(void ***matriz, int filas, int columnas) {
    if (matriz == NULL) return;

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            free(matriz[i][j]);
        }
        free(matriz[i]);
    }
    free(matriz);
}

void inventariostatico(){
    int matrix [3][50];
    for(int i = 0;i<3; ++i){
        for(int j = 0; j<50 ; ++j){
            if(i==0){
                matrix[i][j] = j+1; 
            }else{
                matrix[i][j] = 0;
            }
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    } 

}



int main(int argc, char *argv[]) {

    //==========================================p1 inventario 
    clock_t start = clock();
    inventariostatico();
    clock_t end = clock();
    printf("%d",end);
    printf("\n");

    int filas , columnas; 
    filas = 2 ; columnas = 50;
    struct inventario a; 
    a.chest = inventariocustome(filas,columnas);
    for (int i = 0; i < filas; ++i) {   
        for (int j = 0; j < columnas; ++j) {
            printf("%5d", *(TIPO *) a.chest[i][j]); // Ajusta %5d según el tipo de dato
        }
        printf("\n");


    }
    //==========================================p2 inventario multiples 
    struct inventario cofres[130];

    }
