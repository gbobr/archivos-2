#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Incluyo biblioteca personalizada alumno.h
#include "alumno.h"

int main(int argc, char* argv[])
{
	int resultado;
	if(argc >= 2) //Este programa recibe como parametro por linea de comandos el nombre del archivo a procesar, de no haber parametros abre test/happy.in por defecto
		resultado=procesar_archivo(argv[1]);
	else
		resultado=procesar_archivo("test/happy.in");
	
	return resultado; //Devuelvo el codigo de estado devuelto por procesar_archivo
}
