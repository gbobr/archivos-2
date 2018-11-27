#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"


//Implemente su código a continuación:

int procesar_archivo(char * path)
{
    struct alumno_t alumnos;
    int f_lectura;
    FILE *fachero;
    fachero = fopen("happy.in", "r");
    
    
    if (fachero)
        printf("Fichero Abierto.");
    else{
        printf("Error al abrir el fichero.(CODIGO DE ERROR: 66)");
        return 66;
    }
    
    printf("\nLos siguientes alumnos son aquellos que aprobaron: \n");
    
    while(feof(fachero)){
        f_lectura = fread(&alumno,sizeof(struct alumno_t), 1, fachero);
        if(!feof(fachero)){
            if(feof(fachero != 1)){
                printf("Error al leer el fichero. (CODIGO DE ERROR: 65)");
                return 65;
            }
            printf("Error desconocido. (CODIGO DE ERROR: 74)");
            return 74;
        }
        else{
            if(alumno.promedio >= 7){
                printf("DNI: %d | Promedio: %d\n");
                return 0;
            }
            
        }
        
    }
    printf("Error desconocido. (CODIGO DE ERROR: 1)");
    return 1;
}
