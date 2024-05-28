#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_APELLIDOS 50
#define MAX_CARGO 50
#define MAX_REGISTROS 1000

typedef struct {
    char dni[10];
    char nombre[MAX_NOMBRE];
    char apellidos[MAX_APELLIDOS];
    char sexo;
    char cargo[MAX_CARGO];
    float salario;
} Empleado;

char* categorizarSalario(float salario) {
    if (salario > 3000)
        return "Altos";
    else if (salario > 1500)
        return "Medios";
    else
        return "Bajos";
}

int main() {
    FILE *archivo;
    Empleado empleados[MAX_REGISTROS];
    int numEmpleados = 0;

    archivo = fopen("empleados.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while (fread(&empleados[numEmpleados], sizeof(Empleado), 1, archivo)) {
        numEmpleados++;
    }

    fclose(archivo);

    printf("DNI\tNombre\tApellidos\tSexo\tCargo\tSalario\tCategoría\n");
    for (int i = 0; i < numEmpleados; i++) {
        printf("%s\t%s\t%s\t%c\t%s\t%.2f\t%s\n",
               empleados[i].dni,
               empleados[i].nombre,
               empleados[i].apellidos,
               empleados[i].sexo,
               empleados[i].cargo,
               empleados[i].salario,
               categorizarSalario(empleados[i].salario));
    }

    return 0;
}