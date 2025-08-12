#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int id;
    float pm25;
    float co;
    float temperatura;
    float humedad;
    char fecha[12];
} RegistroAire;

void generarDatosAire(RegistroAire *registro, int id) {
    registro->pm25 = ((float)rand() / RAND_MAX) * 80.0;
    registro->co = ((float)rand() / RAND_MAX) * 15.0;
    registro->temperatura = ((float)rand() / RAND_MAX) * (40.0 - (-10.0)) + (-10.0);
    registro->humedad = ((float)rand() / RAND_MAX) * 100.0;
    registro->id = id;

    int dia = rand() % 28 + 1;
    int mes = rand() % 12 + 1;
    int year = rand() % 36 + 1990;

    sprintf(registro->fecha, "%02d/%02d/%d", dia, mes, year);
}

int main() {
    srand(time(NULL));

    RegistroAire *registros = (RegistroAire *) malloc(4 * sizeof(RegistroAire));
    if (registros == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        generarDatosAire(&registros[i], i + 1);
    }

    float sumaCO = 0.0;
    float pm25MAX = registros[0].pm25;
    float tempMin = registros[0].temperatura;

    for (int i = 0; i < 4; i++) {
        printf("\n====== REGISTRO %d ======\n", i + 1);
        printf("ID: %d\n", registros[i].id);
        printf("Fecha: %s\n", registros[i].fecha);
        printf("PM2.5: %.2f ug/m3\n", registros[i].pm25);
        printf("CO: %.2f ppm\n", registros[i].co);
        printf("Temperatura: %.2f C\n", registros[i].temperatura);
        printf("Humedad: %.2f %%\n", registros[i].humedad);

        if (registros[i].pm25 > 35.0) {
            printf("ALERTA: PM2.5 excede el limite (%.2f ug/m3)\n", registros[i].pm25);
        }

        printf("=========================\n");

        sumaCO += registros[i].co;

        if (registros[i].pm25 > pm25MAX) {
            pm25MAX = registros[i].pm25;
        }

        if (registros[i].temperatura < tempMin) {
            tempMin = registros[i].temperatura;
        }
    }

    float promedioCO = sumaCO / 4.0;

    printf("\n--- ANALISIS GENERAL ---\n");
    printf("Promedio de CO: %.2f ppm\n", promedioCO);
    printf("Mayor PM2.5 registrado: %.2f ug/m3\n", pm25MAX);
    printf("Temperatura minima registrada: %.2f C\n", tempMin);

    int opcionBusqueda;
    printf("\nOpciones de busqueda:\n");
    printf("1. Buscar por ID\n");
    printf("2. Buscar por rango de fechas\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcionBusqueda);

    if (opcionBusqueda == 1) {
        int idBuscado;
        printf("Ingrese el ID a buscar: ");
        scanf("%d", &idBuscado);

        int encontrado = 0;
        for (int i = 0; i < 4; i++) {
            if (registros[i].id == idBuscado) {
                printf("\nRegistro encontrado:\n");
                printf("ID: %d\n", registros[i].id);
                printf("Fecha: %s\n", registros[i].fecha);
                printf("PM2.5: %.2f ug/m3\n", registros[i].pm25);
                printf("CO: %.2f ppm\n", registros[i].co);
                printf("Temperatura: %.2f C\n", registros[i].temperatura);
                printf("Humedad: %.2f %%\n", registros[i].humedad);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("No se encontro un registro con ese ID.\n");
        }

    } else if (opcionBusqueda == 2) {
        char fechaInicio[12], fechaFin[12];
        printf("Ingrese fecha inicial (dd/mm/yyyy): ");
        scanf("%s", fechaInicio);
        printf("Ingrese fecha final (dd/mm/yyyy): ");
        scanf("%s", fechaFin);

        printf("\nRegistros entre %s y %s:\n", fechaInicio, fechaFin);
        int encontrados = 0;

        for (int i = 0; i < 4; i++) {
            if (strcmp(registros[i].fecha, fechaInicio) >= 0 &&
                strcmp(registros[i].fecha, fechaFin) <= 0) {
                printf("\nID: %d\n", registros[i].id);
                printf("Fecha: %s\n", registros[i].fecha);
                printf("PM2.5: %.2f ug/m3\n", registros[i].pm25);
                printf("CO: %.2f ppm\n", registros[i].co);
                printf("Temperatura: %.2f C\n", registros[i].temperatura);
                printf("Humedad: %.2f %%\n", registros[i].humedad);
                encontrados++;
            }
        }

        if (encontrados == 0) {
            printf("No se encontraron registros en ese rango.\n");
        }
    } else {
        printf("Opcion no valida.\n");
    }

    free(registros);
    return 0;
}

