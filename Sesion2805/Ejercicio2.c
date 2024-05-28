#include <stdio.h>
#include <stdlib.h>

#define MAX_REGISTROS 5

struct Registro{
    char nombre[50];
    int edad;
    char direccion[100];
    char ciudad[50];
    char telefono[15];
};

int main(){
    FILE *archivo;
    struct Registro agenda[MAX_REGISTROS];

    printf("Ingrese los datos de %d registros: \n", MAX_REGISTROS);
    for(int i = 0; i < MAX_REGISTROS; i++){
        printf("Registro %d\n", i+1);
        printf("Nombre: ");
        scanf("%s", agenda[i].nombre);
        printf("Edad: ");
        scanf("%d", &agenda[i].edad);
        printf("Direccion: ");
        scanf("%s", agenda[i].direccion);
        printf("Ciudad: ");
        scanf("%s", agenda[i].ciudad);
        printf("Telefono: ");
        scanf("%s", agenda[i].telefono);
    }

    archivo = fopen("agenda.dat", "wb");
    if(archivo == NULL){
        printf("Error al abrir el archivo.");
        exit(1);
    }

fwrite(agenda, sizeof(struct Registro), MAX_REGISTROS, archivo);
fclose(archivo);

archivo = fopen("agenda.dat", "rb");
if(archivo == NULL){
    printf("Error al abrir el archivo.");
    exit(1);
}
printf("\nRegistros almacenados: \n");
fread(agenda, sizeof(struct Registro), MAX_REGISTROS, archivo);
for(int i = 0; i < MAX_REGISTROS; i++){
    printf("Registro %d\n", i+1);
    printf("Nombre: %s\n", agenda[i].nombre);
    printf("Edad: %d\n", agenda[i].edad);
    printf("Direccion: %s\n", agenda[i].ciudad);
    printf("Ciudad; %s\n", agenda[i].ciudad);
    printf("Telefono: %s\n", agenda[i].telefono);
}
fclose(archivo);

return 0;
}