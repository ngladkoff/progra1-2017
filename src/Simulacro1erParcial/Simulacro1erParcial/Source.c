#include <stdlib.h>
#include <stdio.h>

// int ProductoMasEconomico(int vector[]);

int ContieneVocales(char vector[], int largo);
int CantidadVocales(char vector[], int largo);

int EsBisiesto(int anio);

int main(void) {
	int respuesta = 0;
	char conVocales[] = { 'a', 'C', 'Z', 'Z' };
	char sinVocales[] = { 'Z', 'C', 'D', 'S' };

	if (ContieneVocales(sinVocales, 4) == 1)
	{
		printf("Tiene Vocales\n");
	}
	else {
		printf("No tiene Vocales\n");
	}

	respuesta = ContieneVocales(conVocales, 4);

	if (respuesta == 1)
	{
		printf("Tiene Vocales\n");
	}
	else {
		printf("No tiene Vocales\n");
	}

	//char productos[5] = { 'A','B','C','D','E' };
	//int precios[5] = { 350, 200, 17, 190, 80 };

	//printf("El producto mas economico es: %c\n", productos[ProductoMasEconomico(precios)]);

	system("pause");
} 

int ContieneVocales(char vector[], int largo) {
	int idx = 0;

	for (idx = 0; idx < largo; idx++) {
		
		switch (vector[idx])
		{
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
			return 1;
		}
		
		//if (vector[idx] == 'A' || vector[idx] == 'E' || vector[idx] == 'I' || vector[idx] == 'O' || vector[idx] == 'U' || vector[idx] == 'a' || vector[idx] == 'e' || vector[idx] == 'i' || vector[idx] == 'o' || vector[idx] == 'u') {
		//	return 1;
		//}
	}

	return 0;
}

int CantidadVocales(char vector[], int largo) {
	int idx;
	int contador = 0;

	for (idx = 0; idx < largo; idx++) {
		if (vector[idx] == 'A' || vector[idx] == 'E' || vector[idx] == 'I' || vector[idx] == 'O' || vector[idx] == 'U' || vector[idx] == 'a' || vector[idx] == 'e' || vector[idx] == 'i' || vector[idx] == 'o' || vector[idx] == 'u') {
			contador++;
		}
	}
	return contador;
}

//int ProductoMasEconomico(int vector[]) {
//	int i = 0;
//	int menor= vector[0];
//	int posicionMenor= 0;
//
//	// Buscar el menor
//	for (i = 0; i < 5; i++) {
//		if (vector[i] < menor) {
//			menor = vector[i];
//			posicionMenor = i;
//		}
//	}
//
//	return posicionMenor;
//}

int EsBisiesto(int anio) {
	if (anio % 4 == 0)
	{
		if (anio % 100 == 0) {
			if (anio % 400 == 0) {
				return 1;
			}
			return 0;
		}
		return 1;
	}
	return 0;
}