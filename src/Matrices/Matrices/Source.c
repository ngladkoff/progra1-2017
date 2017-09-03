#pragma warning (disable: 4996)
#include <stdlib.h>
#include <stdio.h>
#include "Constantes.c"

int main(void) {
	int i;
	int j;
	int alumnos[MAXFILAS][2] = { 0 };

	for (i = 0; i < MAXFILAS; i++)
	{
		for (j = 0; j < 2; j++) {
			printf("%d\t", alumnos[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	alumnos[2][0] = 7;
	alumnos[2][1] = 8;

	for (i = 0; i < MAXFILAS; i++)
	{
		for (j = 0; j < 2; j++) {
			printf("%d\t", alumnos[i][j]);
		}
		printf("\n");
	}

	system("pause");
}


