#include <stdio.h>
#include <stdlib.h>

struct Registro{
    char nombre[50];
    int edad;
    char direccion[100];
    char ciudad[50];
    char telefono[15];
};

int main(){
    FILE *archivo;
    archivo = fopen("agenda.dat", "wb");

    if(archivo == NULL){
        printf("Error al abrir el archivo.");
        exit(1);
    }

        struct Registro persona;

        printf("Ingrese el nombre: ");
        scanf("%s", persona.nombre);
        printf("Ingrese la edad: ");
        scanf("%d", &persona.edad);
        printf("Ingrese la direccion: ");
        scanf("%s", persona.direccion);
        printf("Ingrese la ciudad: ");
        scanf("%s", persona.ciudad);
        printf("Ingrese el telefono: ");
        scanf("%s", persona.telefono);

        fwrite(&persona, sizeof(struct Registro), 1, archivo);

        fclose(archivo);

        printf("Registro guardado exitosamente en agenda.dat\n");

        return 0;
}