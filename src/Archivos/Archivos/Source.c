/*
	Agenda
	- DNI
	- Ape
	- Nomb
	- Tel
	- email
	- fecha nacimiento

	Funcionalidades:
	-Menu
	-Agregar registro
	-Busqueda DNI -> mostrar registro -> preguntar si quiere editar -> Edicion registro
	-Listado por pantalla ordenado por apellido y nombre, con pausa cuando son muchos registros
	-Listado a archivo de texto, ordenado por apellido y nombre
	-Listado a pantalla de registros que cumplen años en un mes indicado con el siguiente formato
	    DIA APELLIDO NOMBRE
	- Borrar Registro
	- Persistencia a largo plazo en archivo binario

	agenda[0].Ape
	*agenda->Ape

*/


#pragma warning (disable: 4996)
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	char Ape[20];
	char Nom[20];
	char Tel[20];
} tAgenda;

int main(void)
{
	tAgenda Agenda[3] = { {"ape1", "nomb1", "Telef1"},{ "ape2", "nomb2", "Telef2" },{ "ape3", "nomb3", "Telef3" } };
	tAgenda Agenda2[3] = { 0 };
	char cadena[100];
	FILE *f;
	int i;

	/*
	f = fopen("t:\\miArchivo.txt", "rt");
	// r -> lectura
	// w -> escritura. si no existe archivo lo crea. si existe lo sobreescribe
	// a -> agregar. si no existe lo crea. si existe lo usa sin borrar contenido
	// r+ -> lectura y escritura. si no existe archivo da error.
	// w+ -> lectura y escritura. si no existe lo crea. si existe borra contenido.
	// a+ -> lectura y agregar. si no existe lo crea. si existe lo usa sin borrar contenido.
	// b -> abre archivo binario
	// t -> abre archivo texto

	if (f == NULL)
	{
		printf("no se pudo abrir el archivo");
		system("pause");
		exit(EXIT_FAILURE);
	}

	// fprintf(f, "Hola Rusia 2018\n"); // guardar texto en archivo de texto

	fgets(cadena, 100, f);
	printf("%s", cadena);

	while (!feof(f))
	{
		fgets(cadena, 100, f);
		printf("%s", cadena);
	}

	fseek(f, 0, SEEK_SET);

	fgets(cadena, 100, f);
	printf("%s", cadena);

	while (!feof(f))
	{
		fgets(cadena, 100, f);
		printf("%s", cadena);
	}

	fseek(f, 0, SEEK_SET);	

	fgets(cadena, 100, f);
	printf("%s", cadena);

	while (!feof(f))
	{
		fgets(cadena, 100, f);
		printf("%s", cadena);
	}



	//for (i = 0; i < 3; i++) {
	//	fgets(cadena, 100, f); // leer archivo texto. 
	//	printf("%s", cadena);
	//}

	//fgets(cadena, 100, f);
	//printf("%s", cadena);

	//fgets(cadena, 100, f);
	//printf("%s", cadena);

	*/

	f = fopen("t:\\miAgenda.dat", "r+b");
	if (f == NULL)
	{
		printf("no se pudo abrir el archivo");
		system("pause");
		exit(EXIT_FAILURE);
	}

	i = 0;

	fread(&Agenda2[i], sizeof(tAgenda), 1, f); // leer binario
	printf("Ape: %s, Nomb: %s, Tel: %s\n", Agenda2[i].Ape, Agenda2[i].Nom, Agenda2[i].Tel);


	
	while (!feof(f))
	{
		i++;
		 fread(&Agenda2[i], sizeof(tAgenda), 1, f); // leer binario
		 if (!feof(f))
		 {
			 printf("Ape: %s, Nomb: %s, Tel: %s\n", Agenda2[i].Ape, Agenda2[i].Nom, Agenda2[i].Tel);
		 }
	}
	

	/*
	for (i = 0; i < 3; i++)
	{
		if (Agenda[i].Ape[0] != '\0')
		{
			fwrite(&Agenda[i], sizeof(tAgenda), 1, f); // guardar binario
		}
	}
	*/

	// fwrite(&Agenda[0], sizeof(tAgenda), 3, f); // guardar binario

	fclose(f);
	


	system("pause");
	return 0;
}