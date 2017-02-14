#include <stdio.h>
#include "estrutura.h"
#include "Cliente.h"
#include "FuncoesGerais.h"

void CodigoPostal_Junto(char cp1[], char cp2[]) {
    printf("Codigo Postal:%s-%s\n", cp1, cp2);
}

void listar_CodigoPostal(CODIGO_POSTAL codigo_postal) {
    CodigoPostal_Junto(codigo_postal.cp1, codigo_postal.cp2);
}

void CodigoPostal_Geral(char cp[], unsigned int maximo) {
    PRINT_CP(maximo);
    adicionarNumerosChar(cp, maximo);
}

void adicionar_CodigoPostal(CODIGO_POSTAL *codigo_postal) {
    CodigoPostal_Geral(codigo_postal->cp1, MAXIMO_CP1);
    CodigoPostal_Geral(codigo_postal->cp2, MAXIMO_CP2);
}
