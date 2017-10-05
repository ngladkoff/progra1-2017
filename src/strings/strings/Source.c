#pragma warning (disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int dia;
	int mes;
	int anio;
} fecha;

typedef struct {
	char nombre[50];
	char apellido[50];
	int edad;
	int id;
	fecha fechaNacimiento;
} persona;

int main(void) {

	/*
	char miVariable[] = "Hola Mundo";
	char *mivariableptr = "Hola Mundo";

	char miVariable2[11] = { 'H', 'o', 'l', 'a', '\n', 'M', 'u', 'n', 'd', 'o', '\0' };

	char cadena1[30] = "Hola Mundo";
	char cadena2[20]= "";
	char apellido[30] = "";
	int comparar = 0;
	//char s1[] = "hola";
	//char s2[] = "hola";
	char nombre[30] = "";

	//printf("Ingrese su nombre: \n");
	//scanf("%s", &nombre);

	//strcpy(cadena2, nombre);
	//printf("%s\n", cadena2);
	*/
/*
	char s1[30] = "Hola a todos - Hola a todos";
	char s2[3] = "la";

	char *ptrPosEncontrada;

	printf("s1=   %s    \n", s1);
	printf("s2=%s\n", s2);

	ptrPosEncontrada = strstr(s1, s2);

	if (ptrPosEncontrada == NULL)
	{
		printf("no encontrado\n");
	}
	else {
		printf("strstr(s1,s2) = %s\n", ptrPosEncontrada);
	}

*/
	/*
	char s1[30] = "Hola a todos - Hola a todos";
	char c = 'l';

	char *ptrPosEncontrada;

	printf("s1=   %s    \n", s1);
	printf("c=%c\n", c);

	ptrPosEncontrada = strchr(s1, c);

	if (ptrPosEncontrada == NULL)
	{
		printf("no encontrado\n");
	}
	else {
		printf("strstr(s1,s2) = %s\n", ptrPosEncontrada);
	}
	*/
	//printf("Ingrese su nombre: \n");
	//scanf("%s", &cadena2);
	//printf("Ingrese su apellido: \n");
	//scanf("%s", &apellido);

	//strcat(cadena1, cadena2);

	//printf("%s %s\n", cadena1, apellido);
	//
	//printf("%d\n", strlen(cadena1));

	//comparar = strcmp(s1, s2); // "hola" == "Hola"

	//if (comparar == 0) {
	//	printf("son iguales\n");
	//}
	//else if(comparar > 0)
	//{
	//	printf("cadena 1 es mayor\n");
	//}
	//else
	//{
	//	printf("cadena 1 es menor\n");
	//}

	// printf("%s \n", cadena2);

	// printf("%s \n", miVariable);
	//printf("%s \n", miVariable2);

	fecha miVariableFecha= {.dia = 0, .mes= 0, .anio= 0};

	printf("Ingrese dia: "); 
	scanf("%d", &miVariableFecha.dia);

	printf("Ingrese mes: ");
	scanf("%d", &miVariableFecha.mes);

	printf("Ingrese Anio: ");
	scanf("%d", &miVariableFecha.anio);

	printf("Fecha Ingresada: %d / %d / %d\n", miVariableFecha.dia, 
											  miVariableFecha.mes, 
		                                      miVariableFecha.anio);


	//persona alumnos[30];

	//strcpy(alumnos[0].nombre, "nicolas");
	//	//alumnos[0].apellido
	//alumnos[0].edad = 10;
	//alumnos[0].fechaNacimiento.anio = 2010;
	//alumnos[0].fechaNacimiento.mes = 10;
	//alumnos[0].fechaNacimiento.dia = 1;

	system("pause");
}