#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Incluyo biblioteca personalizada alumno.h
#include "alumno.h"


int procesar_archivo(char * name){
    struct alumno_t alumno;
    int r_lectura;
    FILE* f = fopen(name, "r");
    if(!f){
        printf("Error: abirendo el archivo \n");
        return 66;
    }
    printf("Alumnos aprobados: \n");
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

int main(int argc, char* argv[])
{
	int resultado;
	if(argc >= 2) //Este programa recibe como parametro por linea de comandos el nombre del archivo a procesar, de no haber parametros abre test/happy.in por defecto
		resultado=procesar_archivo(argv[1]);
	else
		resultado=procesar_archivo("test/happy.in");
	
	return resultado; //Devuelvo el codigo de estado devuelto por procesar_archivo
}
