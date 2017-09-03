#include <stdlib.h>
#include <stdio.h>

// Prototipo funcion
int EsCapicua(int matriz[][4], int filas);
// tipo_dato_a_devolver nombre (parametros)

int main(void) {
	// matriz con columnas capicua
	int matriz1[5][4] = { {1,2,2,1}, {2,3,3,4}, {1,1,1,1}, {2,3,3,4}, {1,2,2,1} };
	// matriz con columnas no capicua
	int matriz2[5][4] = { {1,2,2,1}, {2,3,3,2}, {1,1,1,1}, {3,3,3,3}, {1,1,1,1} };
	int respuesta;
	
	respuesta = EsCapicua(matriz2, 5);

	if (respuesta == 1) {
		printf("Es capicua\n");
	}
	else
	{
		printf("No es capicua\n");
	}

	system("pause");
	// system("cls");
	return 0;

}

int EsCapicua(int matriz[][4], int filas) {
	int columna;
	int cantidadCapicua = 0;
	int escapicua = 1;
	int i, j;

	for(columna= 0; columna < 4; columna++)
	{
		j = filas - 1;
		for (i = 0; i < filas; i++) {
			if (matriz[i][columna] != matriz[j][columna]) {
				escapicua = 0;
			}
			j = j - 1;
		}

		/*
		if (matriz[0][columna] == matriz[3][columna])
		{
			if (matriz[1][columna] == matriz[2][columna]) {
				// la columna es capicua
				cantidadCapicua = cantidadCapicua + 1;
			}
		}
		*/
	} 

	return escapicua;

	//if (cantidadCapicua == 4) {
	//	return 1;
	//}
	//else
	//{
	//	return 0;
	//}
}
