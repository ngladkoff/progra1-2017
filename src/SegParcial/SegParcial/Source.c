#pragma warning (disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
	char Nombre[30];
	char Especializacion[30];
	int PartidasGanadas;
	int PartidasPerdidas;
} tCivilizacion;

void AgregarCivilizacion(tCivilizacion v[]);
void Buscar(tCivilizacion v[]);
void Exportar(tCivilizacion v[]);
void Guardar(tCivilizacion v[]);
void Cargar(tCivilizacion v[]);

void main(void) {
	tCivilizacion Civilizaciones[MAX] = {0};
	int op = 0;

	// CargarBinario
	Cargar(Civilizaciones);

	do {
		// MostrarMenu
		system("cls");
		printf("Seleccione 1 para ...., 2 para...., etc etc 0 para salir\n");
		scanf("%i", &op);

		// Ejecutar opcion seleccionada
		switch (op)
		{
		case 1:
			// Agregar Civilización
			AgregarCivilizacion(Civilizaciones);
			break;

		case 2:
			// Buscar
			Buscar(Civilizaciones);
			break;

		case 3:
			// Exportar
			Exportar(Civilizaciones);
			break;
		}

	} while (op != 0);

	// Guardar
	Guardar(Civilizaciones);

	printf("chau");
	system("pause");
	return EXIT_SUCCESS;
}

void AgregarCivilizacion(tCivilizacion v[]) {

	int i;

	for (i = 0; i < MAX; i++)
	{
		if (strcmp(v[i].Nombre, "") == 0) {
			printf("Ingrese Nombre: ");
			scanf("%s", &v[i].Nombre);
			printf("Ingrese Especializacion: ");
			scanf("%s", &v[i].Especializacion);
			printf("Ingrese partidas ganadas: ");
			scanf("%i", &v[i].PartidasGanadas);
			printf("Ingrese partidas perdidas: ");
			scanf("%i", &v[i].PartidasPerdidas);
			return;
		}
	}
}

void Buscar(tCivilizacion v[]) {
	int i;
	char valorABuscar[30];

	printf("ingrese el nombre a buscar: ");
	scanf("%s", &valorABuscar);

	for (i = 0; i < MAX; i++)
	{
		if (strcmp(v[i].Nombre, valorABuscar) == 0) {
			printf("Nombre: %s\n", v[i].Nombre);
			printf("Especializacion: %s\n", v[i].Especializacion);
			printf("Partidas Ganadas: %i\n", v[i].PartidasGanadas);
			printf("Partidas Perdidas: %i\n", v[i].PartidasPerdidas);
			system("pause");
			return;
		}
	}
}

void Exportar(tCivilizacion v[]) {
	int i;
	FILE *f;
	f = fopen("salida.txt", "wt");
	if (f == NULL)
	{
		printf("No se pudo abrir el archivo");
		system("pause");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < MAX; i++)
	{
		if (strcmp(v[i].Nombre, "") != 0) {
			fprintf(f,"Nombre: %s\n", v[i].Nombre);
			fprintf(f,"Especializacion: %s\n", v[i].Especializacion);
			fprintf(f,"Partidas Ganadas: %i\n", v[i].PartidasGanadas);
			fprintf(f,"Partidas Perdidas: %i\n", v[i].PartidasPerdidas);
			fprintf(f, "-----------------------------------------\n");
		}
	}
	fclose(f);
}


void Guardar(tCivilizacion v[]) {
	int i;
	FILE *f;
	f = fopen("datos.dat", "wb");
	if (f == NULL)
	{
		printf("No se pudo abrir el archivo");
		system("pause");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < MAX; i++)
	{
		fwrite(&v[i], sizeof(tCivilizacion), 1, f);
	}
	fclose(f);
}

void Cargar(tCivilizacion v[]) {
	int i;
	FILE *f;
	f = fopen("datos.dat", "a+b");
	if (f == NULL)
	{
		printf("No se pudo abrir el archivo");
		system("pause");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < MAX; i++)
	{
		fread(&v[i], sizeof(tCivilizacion), 1, f);

		if (feof(f))
		{
			break;
		}
	}
	fclose(f);
}











