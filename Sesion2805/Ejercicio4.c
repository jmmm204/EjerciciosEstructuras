#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODIGO 20
#define MAX_PROVEEDOR 50
#define MAX_ARTICULOS 1000

typedef struct {
    char codigo[MAX_CODIGO];
    int nivelMinimo;
    int nivelActual;
    char proveedor[MAX_PROVEEDOR];
    float precio;
} Articulo;

int main() {
    FILE *archivo;
    Articulo stock[MAX_ARTICULOS];
    int numArticulos = 0;

    archivo = fopen("stock.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while (fread(&stock[numArticulos], sizeof(Articulo), 1, archivo)) {
        numArticulos++;
    }

    fclose(archivo);

    printf("Alertas de Stock:\n");
    printf("Codigo\tNivel_Minimo\tNivel_Actual\tProveedor\tPrecio\n");
    for (int i = 0; i < numArticulos; i++) {
        if (stock[i].nivelActual < stock[i].nivelMinimo) {
            printf("%s\t%d\t\t%d\t\t%s\t%.2f\tAlerta: Hacer Pedido\n",
                   stock[i].codigo,
                   stock[i].nivelMinimo,
                   stock[i].nivelActual,
                   stock[i].proveedor,
                   stock[i].precio);
        } else {
            printf("%s\t%d\t\t%d\t\t%s\t%.2f\n",
                   stock[i].codigo,
                   stock[i].nivelMinimo,
                   stock[i].nivelActual,
                   stock[i].proveedor,
                   stock[i].precio);
        }
    }

    return 0;
}