#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int intensidad;
    float promedio;
    float nivelCongestion;
    int tiempoEspera;

}DatosTrafico;

void generarDatos(DatosTrafico *sensor, int hora){
  sensor-> intensidad = rand() % 201;
  sensor-> promedio = ((float) rand() / RAND_MAX) * (120.0 - 20.0) + 20.0;
  sensor-> nivelCongestion = ((float)rand()/ RAND_MAX) * 100.0;

  if (hora == 8 || hora == 16) {
    sensor -> tiempoEspera = (rand() %81) + 100;
  } else {
    sensor -> tiempoEspera = (rand() % 51) + 10;
  }
}

void alertarCongestion(DatosTrafico *sensor){
if (sensor->nivelCongestion > 70 || sensor->tiempoEspera > 120) {
    printf("CONGESTION CRITICA: %.2f%% - TIEMPO DE ESPERA %d segundos\n", sensor->nivelCongestion, sensor->tiempoEspera);
 }
}

int main()
{
    srand(time(NULL));

    int lecturasDiarias = 3;
    DatosTrafico *lecturas = (DatosTrafico *) malloc(lecturasDiarias * sizeof(DatosTrafico));


    if (lecturas == NULL){
        printf("no se pudo asignar memoria \n");
        return 1;
    }

    int horas[3] = {0, 8, 16};

    for (int i = 0; i < 3; i++) {
     printf("\n====== LECTURA %d ======\n", i + 1);
    printf("Hora: %d\n", horas[i]);

    generarDatos(&lecturas[i], horas[i]);
    alertarCongestion(&lecturas[i]);

    printf("Intensidad: %d veh/min\n", lecturas[i].intensidad);
    printf("Velocidad: %.2f km/h\n", lecturas[i].promedio);
    printf("Congestión: %.2f%%\n", lecturas[i].nivelCongestion);
    printf("Tiempo de espera: %d s\n", lecturas[i].tiempoEspera);
    printf("=========================\n");
    }

    free(lecturas);

    return 0;
}
