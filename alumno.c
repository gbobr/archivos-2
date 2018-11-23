#include <stdlib.h>
#include <stdio.h>
#include "alumno.h"
 //Implemente su código a continuación:

 int procesar_archivo(char * path)
{
struct alumno_t alumno;
FILE* lista_alumnos;
lista_alumnos = fopen(path,"r");
int leer;
if(!lista_alumnos)
{
  printf("Error en la apertura del archivo");
  return 66;
}
printf("Alumnos aprobados:\n");
while(!feof(lista_alumnos))
{
  leer = fread(&alumno, sizeof(struct alumno_t), 1, lista_alumnos);
  if(!feof(lista_alumnos)) {
  if(leer != 1)
  {
    printf("Error en la lectura del archivo");
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
