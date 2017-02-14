#include <stdio.h>
#include "estrutura.h"
#include "LP_Leitura.h"
#include "LP_Utils.h"
#include <float.h>

void listar_coordenada_geral(float latitude, char tipo[]) {
    printf("%s: %.2f\n", tipo, latitude);
}

void listar_coordenada(COORDENADAS coordenadas) {
    listar_coordenada_geral(coordenadas.latitude, LATITUDE);
    listar_coordenada_geral(coordenadas.longitude, LONGITUDE);
}

void adicionar_latitude(float *latitude) {
    readFloat(latitude, -FLT_MAX, FLT_MAX, "Coordenada X: ");
}

void adicionar_longitude(float *longitude) {
    readFloat(longitude, -FLT_MAX, FLT_MAX, "Coordenada Y: ");
}

void adicionar_coordenada(COORDENADAS *coordenadas) {
    adicionar_latitude(&coordenadas->latitude);
    adicionar_longitude(&coordenadas->longitude);
}