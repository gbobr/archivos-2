#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"


//Implemente su código a continuación:

int procesar_archivo(char * path)
{
    struct alumno_t Alumno;
    FILE* Listado_Alumnos;
    Listado_Alumnos = fopen(path,"r");
    int Lectura;
    if(!Listado_Alumnos)
    {
        printf("Error al abrir el archivo");
        return 66;
    }
        printf("Alumnos aprobados:\n");
    while(!feof(Listado_Alumnos))
    {
        Lectura = fread(&Alumno, sizeof(struct alumno_t), 1, Listado_Alumnos);
        if(!feof(Listado_Alumnos))
        {
            if(Lectura != 1)
            {
                printf("Error al leer el archivo");
                return 65;
            }
            else
            {
            if(Alumno.promedio >= 7)
            {
                printf("DNI: %d | Promedio: %d\n", Alumno.dni, Alumno.promedio);
            }
            }
        }
    }
    return 0;
 }
