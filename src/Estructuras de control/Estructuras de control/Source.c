#include <stdlib.h>
#include <stdio.h>

int main()
{
	int contador;
	int calificacion;
	int total;
	int promedio;

	total = 0;
	contador = 0;
	calificacion = 1;

	while (calificacion != 0) {
		printf("introduzca la califiacion ");
		scanf("%d", &calificacion);
		total = total + calificacion;
		if (calificacion != 0) {
			contador = contador + 1;
		}
	}

	promedio = total / contador;
	printf("El promedio del grupo es: %d\n", promedio);
	system("pause");
	return 0;
}