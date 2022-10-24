#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMN 4


typedef struct{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} eNotebook;


float aplicarDescuento(float precio);
int contarCaracteres(char cadena[20], char letra);
int ordenarNotebooks(eNotebook vecNotebook[], int tam);



int main(){
    float precioProducto = 235;
    float productoDescuento;

    productoDescuento = aplicarDescuento(precioProducto);

    printf("%.2f", productoDescuento);

    printf("\n\n");


    char palabra[20];
    char letra;
    int cantVeces;

    printf("Ingrese palabra: ");
    scanf("%s", palabra);
    fflush(stdin);
    printf("\nIngrese letra: ");
    scanf("%c", &letra);

    cantVeces = contarCaracteres(palabra, letra);

    printf("\n\nCantidad de veces que %c esta en %s: %d", letra, palabra, cantVeces);

    printf("\n\n");


    eNotebook notebook[TAMN] = {
        {20000, "procesador2", "marca1", 20000},
        {20001, "procesador4", "marca2", 40000},
        {20002, "procesador 3", "marca1", 50000},
        {20003, "procesador1", "marca3", 45000}
    };

    ordenarNotebooks(notebook, TAMN);

    for(int i = 0; i < TAMN; i++){
            printf("\n");
        printf("%d    %s    %s      %.2f", notebook[i].id, notebook[i].procesador, notebook[i].marca, notebook[i].precio);
    }



    return 0;
}


float aplicarDescuento(float precio){
    float porcentaje = 0.05;
    float descuento;
    float productoConDescuento;

    descuento = porcentaje * precio;
    productoConDescuento = precio - descuento;


    return productoConDescuento;
}


int contarCaracteres(char cadena[20], char letra){
    int cantCaracteres;
    int cantApariciones = 0;

    cantCaracteres = strlen(cadena);

    for(int i = 0; i < cantCaracteres; i++){
        if(letra == cadena[i]){
            cantApariciones++;
        }
    }

    return cantApariciones;
}


int ordenarNotebooks(eNotebook vecNotebook[], int tam){
    int todoOk = 0;
    eNotebook auxNotebook;

    if(vecNotebook != NULL && tam > 0){
        for(int i = 0 ; i < tam  - 1 ; i++){
            for(int j = i + 1 ; j < tam ; j++){
                if(strcmp(vecNotebook[i].marca, vecNotebook[j].marca) > 0 || (strcmp(vecNotebook[i].marca, vecNotebook[j].marca) == 0 && vecNotebook[i].precio > vecNotebook[j].precio)){
                    auxNotebook = vecNotebook[i];
                    vecNotebook[i] = vecNotebook[j];
                    vecNotebook[j] = auxNotebook;
                }
            }
        }

        todoOk = 1;
    }

    return todoOk;
}
