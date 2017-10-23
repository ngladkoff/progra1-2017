#pragma warning (disable: 4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Defino mis constantes -- ATENCION van sin punto y coma (;) al final
#define MAX_STRCHAR 30
#define MAX_AGENDA 100

// Creo un tipo de datos "custom" para los vectores de caracteres y lo llamo "string"
typedef char string[MAX_STRCHAR];

// Creo un tipo de datos custom del tipo estructura para las fechas
typedef struct {
	int Dia;
	int Mes;
	int Anio;
} tFecha;

// Creo un tipo de datos custom del tipo estructura para las personas
typedef struct {
	int Dni;
	string Apellido;
	string Nombre;
	string Telefono;
	string Email;
	tFecha FechaNacimiento;
} tPersona;

// Prototipos de las funciones
void CargarDatos(tPersona Agenda[]);
void MostrarMenu();
int PedirEntero(string mensaje);
void EjecutarOpcion(int opcionMenu, tPersona Agenda[]);
void GrabarDatos(tPersona Agenda[]);
void Agregar(tPersona Agenda[]);
void Buscar(tPersona Agenda[]);
void Listar(tPersona Agenda[]);
void Exportar(tPersona Agenda[]);
void Cumpleaños(tPersona Agenda[]);
int BuscarDNI(int dni, tPersona Agenda[]);
void PedirString(string mensaje, char *cadena);
tFecha PedirFecha(string mensaje);
tPersona CargarPersona(tPersona persona);
void MostrarPersona(tPersona persona);
void OrdenarAgenda(tPersona Agenda[]);

int main(void) {
	// Creo el vector Agenda del tipo persona para guardar los datos en memoria
	tPersona Agenda[MAX_AGENDA] = { 0 }; // pongo = {0}; para inicializar todos los datos con un 0

	int opcionMenu = 0;

	CargarDatos(Agenda);

	// Inicio el ciclo del menú
	do {
		MostrarMenu();
		opcionMenu = PedirEntero("");
		EjecutarOpcion(opcionMenu, Agenda);
	} while (opcionMenu != 0);

	GrabarDatos(Agenda);

	return EXIT_SUCCESS;
}

void CargarDatos(tPersona Agenda[]) {
	int i;
	FILE *f;

	f = fopen("c:\\agenda\\agenda.dat", "a+b");
	if (f == NULL)
	{
		printf("no se pudo abrir el archivo");
		system("pause");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < MAX_AGENDA; i++)
	{
		fread(&Agenda[i], sizeof(tPersona), 1, f);
	}

	fclose(f);
}

void MostrarMenu() {
	system("cls");
	printf("##################################\n");
	printf("# AGENDA PROGRAMACION I - MENU   #\n");
	printf("##################################\n");
	printf("# Seleccione una opción:         #\n");
	printf("#  1-Agregar                     #\n");
	printf("#  2-Buscar                      #\n");
	printf("#  3-Listado por pantalla        #\n");
	printf("#  4-Exportar a archivo de texto #\n");
	printf("#  5-Listado cumpleaños          #\n");
	printf("#  0-Salir                       #\n");
	printf("##################################\n");
}

int PedirEntero(string mensaje) {
	int entero;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%i", &entero);
	return entero;
}

void EjecutarOpcion(int opcionMenu, tPersona Agenda[])
{
	switch (opcionMenu)
	{
	case 1:
		Agregar(Agenda);
		break;
	case 2:
		Buscar(Agenda);
		break;
	case 3:
		Listar(Agenda);
		break;
	case 4:
		Exportar(Agenda);
		break;
	case 5:
		Cumpleaños(Agenda);
		break;
	}
}

void GrabarDatos(tPersona Agenda[]) {
	int i;
	FILE *f;
	f = fopen("c:\\agenda\\agenda.dat", "wb");
	if (f == NULL)
	{
		printf("no se pudo abrir el archivo");
		system("pause");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < MAX_AGENDA; i++)
	{
		if (Agenda[i].Dni != 0)
		{
			fwrite(&Agenda[i], sizeof(tPersona), 1, f);
		}
	}

	fclose(f);
}

void Agregar(tPersona Agenda[]) {
	tPersona personaNueva = { 0 };
	int posLibre = 0;
	posLibre = BuscarDNI(0, Agenda);

	if (posLibre == -1) {
		printf("\n\n## ERROR ## La agenda no tiene mas capacidad\n");
		system("pause");
		return;
	}

	Agenda[posLibre] = CargarPersona(personaNueva);
}

tPersona CargarPersona(tPersona persona) {
	system("cls");
	persona.Dni = PedirEntero("\nIngrese el DNI: ");
	PedirString("\nIngrese el APELLIDO: ", &persona.Apellido);
	PedirString("\nIngrese el NOMBRE: ", &persona.Nombre);
	PedirString("\nIngrese el TELEFONO: ", &persona.Telefono);
	PedirString("\nIngrese el EMAIL: ", &persona.Email);
	persona.FechaNacimiento = PedirFecha("\nIngrese la FECHA DE NACIMIENTO: ");

	return persona;
}

void Buscar(tPersona Agenda[]) {
	int dni = 0;
	int posDni = 0;
	int i = 0;
	int opcion = 0;

	system("cls");
	dni = PedirEntero("\nIngrese el DNI a buscar: ");

	posDni = BuscarDNI(dni, Agenda);

	if (posDni == -1)
	{
		printf("\n\n## DNI NO ENCONTRADO ##\n");
		system("pause");
		return;
	}

	system("cls");
	MostrarPersona(Agenda[posDni]);
	opcion = PedirEntero("Seleccione opcion: 1-Editar, 2-Borrar, 0-Salir\n");

	if (opcion == 1) {
		Agenda[posDni] = CargarPersona(Agenda[posDni]);
	}
	else if (opcion == 2)
	{
		Agenda[posDni].Dni = 0;
	}
}

void Listar(tPersona Agenda[]) {
	int i;

	OrdenarAgenda(Agenda);

	for (i = 0; i < MAX_AGENDA; i++)
	{
		if (Agenda[i].Dni != 0)
		{
			MostrarPersona(Agenda[i]);
			printf("\n-------------------------------------------------\n");
		}
	}

	system("pause");
}

void Exportar(tPersona Agenda[]) {
	int i;
	FILE *f;

	f = fopen("c:\\agenda\\agenda.txt", "wt");
	if (f == NULL)
	{
		printf("no se pudo abrir el archivo");
		system("pause");
		exit(EXIT_FAILURE);
	}

	OrdenarAgenda(Agenda);

	for (i = 0; i < MAX_AGENDA; i++)
	{
		if (Agenda[i].Dni != 0)
		{
			fprintf(f, "DNI: %i\n", Agenda[i].Dni);
			fprintf(f, "APELLIDO: %s\n", Agenda[i].Apellido);
			fprintf(f, "NOMBRE: %s\n", Agenda[i].Nombre);
			fprintf(f, "TELEFONO: %s\n", Agenda[i].Telefono);
			fprintf(f, "EMAIL: %s\n", Agenda[i].Email);
			fprintf(f, "FECHA NACIMIENTO: %i / %i / %i\n", Agenda[i].FechaNacimiento.Dia, Agenda[i].FechaNacimiento.Mes, Agenda[i].FechaNacimiento.Anio);
			fprintf(f, "-------------------------------------------------\n");
		}
	}

	fclose(f);

	printf("Se ha exportado el archivo\n");
	system("pause");
}

void Cumpleaños(tPersona Agenda[]) {
	int i;
	int mes;

	OrdenarAgenda(Agenda);

	system("cls");

	mes = PedirEntero("Ingrese el mes a exportar cumpleaños: ");
	printf("\n");

	for (i = 0; i < MAX_AGENDA; i++)
	{
		if (Agenda[i].Dni != 0)
		{
			printf("%i\t%s\t%s\n", Agenda[i].FechaNacimiento.Dia, Agenda[i].Apellido, Agenda[i].Nombre);
		}
	}

	system("pause");
}

int BuscarDNI(int dni, tPersona Agenda[]) {
	int i = 0;

	for (i = 0; i < MAX_AGENDA; i++) {
		if (Agenda[i].Dni == dni)
		{
			return i;
		}
	}

	return -1;
}

void PedirString(string mensaje, char *cadena) {
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", cadena);
}

tFecha PedirFecha(string mensaje) {
	tFecha fecha;
	printf("%s", mensaje);
	fecha.Dia = PedirEntero("\nDia: ");
	fecha.Mes = PedirEntero("\nMes: ");
	fecha.Anio = PedirEntero("\nAnio: ");
	return fecha;
}

void MostrarPersona(tPersona persona) {
	printf("DNI: %i\n", persona.Dni);
	printf("APELLIDO: %s\n", persona.Apellido);
	printf("NOMBRE: %s\n", persona.Nombre);
	printf("TELEFONO: %s\n", persona.Telefono);
	printf("EMAIL: %s\n", persona.Email);
	printf("FECHA NACIMIENTO: %i / %i / %i\n", persona.FechaNacimiento.Dia, persona.FechaNacimiento.Mes, persona.FechaNacimiento.Anio);
}

void OrdenarAgenda(tPersona Agenda[]) {
	int i, j;
	tPersona aux;

	for (i = 0; i < MAX_AGENDA; i++)
	{
		for (j = 0; j < (MAX_AGENDA - 1); j++)
		{
			if (Agenda[j].Dni == 0)
			{
				aux = Agenda[j];
				Agenda[j] = Agenda[j + 1];
				Agenda[j + 1] = aux;
			}
			else if (strcmp(Agenda[j].Apellido, Agenda[j + 1].Apellido) > 0)
			{
				aux = Agenda[j];
				Agenda[j] = Agenda[j + 1];
				Agenda[j + 1] = aux;
			}
			else if (strcmp(Agenda[j].Apellido, Agenda[j + 1].Apellido) == 0)
			{
				if (strcmp(Agenda[j].Nombre, Agenda[j + 1].Nombre) > 0)
				{
					aux = Agenda[j];
					Agenda[j] = Agenda[j + 1];
					Agenda[j + 1] = aux;
				}
			}
		}
	}
}