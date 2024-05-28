#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARNET 20
#define MAX_NOMBRE 50
#define MAX_APELLIDOS 50
#define MAX_ALUMNOS 1000

typedef struct {
    char carnet[MAX_CARNET];
    char nombre[MAX_NOMBRE];
    char apellidos[MAX_APELLIDOS];
    float notaFinal;
} Alumno;

int main() {
    FILE *archivo;
    Alumno alumnos[MAX_ALUMNOS];
    int numAlumnos = 0;
    float notaMasAlta = 0;

    archivo = fopen("calificaciones.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while (fread(&alumnos[numAlumnos], sizeof(Alumno), 1, archivo)) {
        if (alumnos[numAlumnos].notaFinal > notaMasAlta) {
            notaMasAlta = alumnos[numAlumnos].notaFinal;
        }
        numAlumnos++;
    }

    fclose(archivo);

    printf("Todos los registros:\n");
    printf("#Carnet\tNombre\tApellidos\tNota Final\n");
    for (int i = 0; i < numAlumnos; i++) {
        printf("%s\t%s\t%s\t%.2f\n",
               alumnos[i].carnet,
               alumnos[i].nombre,
               alumnos[i].apellidos,
               alumnos[i].notaFinal);
    }

    printf("\nAlumnos con la nota más alta (%.2f):\n", notaMasAlta);
    for (int i = 0; i < numAlumnos; i++) {
        if (alumnos[i].notaFinal == notaMasAlta) {
            printf("#Carnet: %s, Nombre: %s %s\n", alumnos[i].carnet, alumnos[i].nombre, alumnos[i].apellidos);
        }
    }

    float sumaNotas = 0;
    for (int i = 0; i < numAlumnos; i++) {
        sumaNotas += alumnos[i].notaFinal;
    }
    float notaPromedio = sumaNotas / numAlumnos;
    printf("\nNota promedio del curso: %.2f\n", notaPromedio);

    return 0;
}