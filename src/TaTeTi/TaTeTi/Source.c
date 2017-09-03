#pragma warning (disable: 4996)
#include <stdlib.h>
#include <stdio.h>

void Partida();
void Turno(char tablero[][3], int jugador);
void ImprimirTablero(char tablero[][3]);
int EvaluarGanador(char tablero[][3], int jugadas);
// 1: ganador
// 0: no hay ganador
// 2: empate

int main(void)
{
	int i;
	for (i = 0;i < 3;i++)
	{
		Partida();
	}	
	system("pause");
	return 0;
}

void Partida() {
	char tablero[3][3] = { { '1', '2', '3'}, { '4', '5', '6'}, { '7', '8', '9'} };
	int jugador = 1;
	int partidaFinalizada = 0;
	int jugadas = 0;

	while (partidaFinalizada == 0) {
		jugadas = jugadas + 1;

		Turno(tablero, jugador);

		// Evaluar
		partidaFinalizada= EvaluarGanador(tablero, jugadas);

		switch (partidaFinalizada)
		{
		case 1:
			printf("Gana jugador %d\n", jugador);
			system("pause");
			break;
		case 2:
			printf("Empate");
			system("pause");
			break;
		}
		
		// Cambia Jugador
		if (jugador == 1)
		{
			jugador = 2;
		}
		else
		{
			jugador = 1;
		}
	}
}

void Turno(char tablero[][3], int jugador) {
	char casillaSeleccionada = '0';
	int i; int j;
	int encontrado = 0;

	// ImprimirTablero
	ImprimirTablero(tablero);

	// Solicitar casilla
	while (encontrado == 0)
	{
		printf("\nJugador: %d\nSeleccione el nro de casilla:\n", jugador);
		scanf("\n%c", &casillaSeleccionada);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (tablero[i][j] == casillaSeleccionada)
				{
					// lo encontre
					encontrado = 1;
					// Marcar casilla
					if (jugador == 1)
					{
						tablero[i][j] = 'X';
					}
					else {
						tablero[i][j] = 'O';
					}
				}
			}
		}
	}
}

void ImprimirTablero(char tablero[][3]){system("cls");printf(" %c | %c | %c \n", tablero[0][0], tablero[0][1], tablero[0][2]);printf("---+---+---\n");printf(" %c | %c | %c \n", tablero[1][0], tablero[1][1], tablero[1][2]);printf("---+---+---\n");printf(" %c | %c | %c \n",tablero[2][0],tablero[2][1],tablero[2][2]);}

int EvaluarGanador(char tablero[][3], int jugadas)
{
	int i;

	for (i = 0; i < 3; i++)
	{
		if (tablero[i][0] == tablero[i][1] && tablero[i][0] == tablero[i][2])
		{
			return 1;
		}
	}

	for (i = 0; i < 3; i++)
	{
		if (tablero[0][i] == tablero[1][i] && tablero[0][i] == tablero[2][i])
		{
			return 1;
		}
	}

	if (tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2])
	{
		return 1;
	}

	if (tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])
	{
		return 1;
	}

	// hay empate?
	if (jugadas >= 9)
	{
		return 2;
	}

	return 0;
}