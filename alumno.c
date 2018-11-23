#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"


//Implemente su código a continuación:
int procesar_archivo(char * name){
    struct alumno_t alumno;
    int r_lectura;
    FILE* f = fopen(name, "r");
    if(!f){
        printf("Error: abirendo el archivo \n");
        return 66;
    }
    printf("Alumnos aprobados:\n");
    while(!feof(f)){
        r_lectura = fread(&alumno, sizeof(struct alumno_t), 1, f);
        if(!feof(f)) {
            if(r_lectura != 1){
                printf("Error: leyendo el archivo \n");
                return 65;
            }
            if(alumno.promedio >= 7){
                printf("DNI: %d | Promedio: %d\n", alumno.dni, alumno.promedio);
            }
        }
    }
    fclose(f);
    return 0;
}
