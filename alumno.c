#include <stdlib.h>
#include <stdio.h>
#include "alumno.h"
 //Implemente su código a continuación:
  int procesar_archivo(char * path)
{
        struct alumno_t alumno;
        int f_leer;

        FILE* archivo_alumnos; 
         archivo_alumnos = fopen(path,"r");

        
        if(!archivo_alumnos)
        {
            printf("Error al abrir el archivo");
            return 66;
        }

        printf("Alumnos aprobados:\n");
        
        while(!feof(archivo_alumnos))
        {
            f_leer = fread(&alumno, sizeof(struct alumno_t), 1, archivo_alumnos);
            if(!feof(archivo_alumnos)) {
                if(f_leer != 1)
                {
                printf("Error al leer el archivo");
                return 65;
                }
                else if(alumno.promedio >= 7)
                {
                    printf("DNI: %d | Promedio: %d\n", alumno.dni, alumno.promedio);
                }
            }
        }
        return 0;
 }
