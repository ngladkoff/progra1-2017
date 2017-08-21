#pragma warning (disable:4996)

#include <stdlib.h>
#include <stdio.h>

int sumarVector(int v[], int largo);

int main(void) {

	int vector[10] = { 1, 5, 3, 4, 5, 6, 7, 5,9,10 };
	int vector2[5] = { 1,2,3,4,5 };
	int vector3[3] = { 1,2,3 };
	int i;
	
	int contar = 0;

	for (i = 0; i < 10; i++)
	{
		if (vector[i] == 5) {
			contar = contar + 1;
		}
	}
	
	printf("suma: %d\n", sumarVector(vector, 10));
	printf("suma2: %d\n", sumarVector(vector2, 5));
	printf("suma3: %d\n", sumarVector(vector3, 3));
	printf("cuenta: %d\n", contar);
	system("pause");
	return 0;
}

int sumarVector(int v[], int largo) {
	int i;
	int suma = 0;

	for (i = 0; i < largo; i++)
	{
		suma = suma + v[i];
	}
	return suma;
}