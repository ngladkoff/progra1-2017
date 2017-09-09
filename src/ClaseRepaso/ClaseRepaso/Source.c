#pragma warning (disable: 4996)
#include <stdlib.h>
#include <stdio.h>

int sumar(int p1, int p2);
int sumarVector(int vector[], int largo);
int cantidadNegativos(int vector[], int largo);
int esCapicua(int vector[], int largo);
void CargarEstadoAlumno(int vector[][4], int largo);
void ImprimirMatriz(int matriz[][4], int largo); 

int main(void) {
	/*

	// Uso de CLS
	printf("Hola Mundo\n");
	system("pause");
	system("cls");
	printf("Hola 2\n");
	*/
	/*
	// switch vs if
	int sueldo = 11000;
	int bono = 0;

	if (sueldo <= 8000)
	{
		bono = 3000;
	}
	else if (sueldo > 12000)
	{
		bono = 1000;
	}
	else if (sueldo > 8000 && sueldo <= 10000)
	{
		bono = 2000; 
	}
	else
	{
		bono = 2500;
	}

	printf("El bono es: %i\n", bono);
	*/
    /*
	// FOR
	int numero = 0;
	for (numero = 1; numero <= 10; numero++)
	{
		if ((numero % 2) != 0)
		{
			printf("%i\n", numero);
		}
	}

	int contador = 1;
	do
	{
		if ((contador % 2) != 0)
		{
			printf("%i\n", contador);
		}
		contador++;
	} while (contador <= 10);
	*/

	/*
	// do...while
	int opcion = 0;

	do
	{
		printf("seleccione opcion\n");
		scanf("\n%d", &opcion);
	} while (opcion != 0);

	printf("selecciono salir\n");
	*/
	/*
	// funciones
	int r = 0;
	r = sumar(5, 7);
	printf("%d\n", r);
	r = sumar(3, 5);
	printf("%d\n", r);
	r = sumar(2, 4);
	printf("%d\n", r);
	*/
	/*
	// funciones con vectores
	int r = 0;
	int miVector[4] = { 2, 7, 5, 3 };
	int miVector2[5] = { 2, 7, 5, 3, 3 };

	r = sumarVector(miVector, 4);
	printf("%d\n", r);

	r = sumarVector(miVector2, 5);
	printf("%d\n", r);
	*/
	/*
	// float
	float precio = 0;
	float divisor = 0;

	precio = 10;
	divisor = 3;
	printf("%f\n", precio / divisor);
	*/
	/*
	// random
	int valorAleatorio = 0;
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		valorAleatorio = rand();
		printf("%d\n", valorAleatorio);
	}
	*/

	/*
	int r = 0;
	int miVector[4] = { 1, 2, 2, 1 };

	r = esCapicua(miVector, 4);
	printf("%d\n", r);
	*/

	int alumnos[5][4] = { {1, 7, 7, 0},{ 2, 2, 2, 0 },{ 3, 4, 7, 0 },{ 4, 6, 5, 0 },{ 5, 2, 4, 0 } };
	CargarEstadoAlumno(alumnos, 5);
	ImprimirMatriz(alumnos, 5);	
	system("pause");
	return 0;
}

int sumar(int p1, int p2)
{
	int resultado = 0;
	resultado = p1 + p2;
	return resultado;
}

int sumarVector(int vector[], int largo) 
{
	int acumulador = 0;
	int n = 0;

	for (n = 0; n < largo; n++)
	{
		acumulador = acumulador + vector[n];
	}

	return acumulador;
}

int cantidadNegativos(int vector[], int largo)
{
	int cantidad = 0;
	int n = 0;

	for (n = 0; n < largo; n++)
	{
		if (vector[n] < 0)
		{
			cantidad = cantidad + 1; // cantidad++;
		}
	}

	return cantidad;
}

int esCapicua(int vector[], int largo)
{
	int esCapicua = 1;
	int i = 0;
	int j = largo - 1;

	for (i = 0; i < largo; i++)
	{
		if (vector[i] != vector[j])
		{
			esCapicua = 0;
		}
		j--;
	}

	return esCapicua;
}

void CargarEstadoAlumno(int matriz[][4], int largo) {
	int n;

	for (n = 0; n < largo; n++)
	{
		if (matriz[n][1] >= 7 && matriz[n][2] >= 7)
		{
			matriz[n][3] = 3;
		}
		else {
			if (matriz[n][1] < 4 && matriz[n][2] < 4) {
				matriz[n][3] = 0;
			}
			else
			{
				if (matriz[n][1] < 4 || matriz[n][2] < 4)
				{
					matriz[n][3] = 1;
				}
				else
				{
					matriz[n][3] = 2;
				}
			}
		}
	}
}

void ImprimirMatriz(int matriz[][4], int largo) {
	int fila = 0;
	int j = 0;

	for (fila = 0; fila < largo; fila++)
	{
		// printf("%i %i %i %i\n", matriz[fila][0], matriz[fila][1], matriz[fila][2], matriz[fila][3]);

		for (j = 0; j < 4; j++)
		{
			printf("%i ", matriz[fila][j]);
		}
		printf("\n");
	}
}