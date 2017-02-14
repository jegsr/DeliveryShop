#include <stdio.h>
#include "estrutura.h"
#include "LP_Leitura.h"
#include "LP_Utils.h"
#include "Coordenadas.h"
#include "CodigoPostal.h"

void listar_Rua(char rua[]) {
    printf("Rua: %s\n", rua);
}

void listar_InfoMorada(INFO_MORADA info_morada) {
    listar_Rua(info_morada.rua);
    listar_CodigoPostal(info_morada.codigo_postal);
    listar_coordenada(info_morada.coordenadas);
}

void adicionar_Rua(char rua[]) {
    readString(rua, MAXIMO_MORADA, "Rua: ");
}

void adicionar_InfoMorada(INFO_MORADA *info_morada) {
    adicionar_Rua(info_morada->rua);
    adicionar_CodigoPostal(&info_morada->codigo_postal);
    adicionar_coordenada(&info_morada->coordenadas);
}


