
#include <stdio.h>
#include <string.h>
#include "estrutura.h"
#include "LP_Leitura.h"
#include "LP_Utils.h"
#include "FuncoesGerais.h"

void adicionar_Cliente(CLIENTE *cliente) {

    adicionar_Nome(cliente->nome);
    PRINT_CARTAO_CREDITO;
    adicionarNumerosChar(cliente->cartao_credito, MAXIMO_CARTAO_CREDITO);

    unsigned int op, i = 0;
    do {
        PRINT_TELEFONE;
        adicionarNumerosChar(cliente->telefone[i++], MAXIMO_NUMERO_TELEFONE);
        if (i < 2)
            readInt(&op, 1, 2, "Pretende colocar mais um numero de telefone? ( 1=Sim\t 2=Nao )");
    } while (op != 2 && i < MAXIMO_TELEFONES);
    adicionar_ID(&cliente->contadorTelefone, i);

}

void listar_CartaoCredito(char cartao[]) {
    printf("Cartao de Credito: %s\n", cartao);
}

void listar_Telefone(char telefone[]) {
    printf("Contacto: %s\n", telefone);
}

void listar_Cliente(CLIENTE cliente) {

    listar_ID(cliente.id_registo, Cliente);
    listar_Nome(cliente.nome, Cliente);
    listar_CartaoCredito(cliente.cartao_credito);
    int i = 0;
    while (i < cliente.contadorTelefone) {
        listar_Telefone(cliente.telefone[i]);
        i++;
    }

}

void listarTodos_Cliente(CLIENTE cliente[], unsigned const int contador) {
    int i = 0;
    while (i < contador) {
        listar_Cliente(cliente[i]);
        i++;
    }
    if (contador == 0)
        PRINT_PESQUISA_INVALIDO;
}

void eliminar_Cliente(CLIENTE cliente[], unsigned int *contador, unsigned const int id) {
    int i;
    for (i = id; i < (*contador) - 1; i++) {
        cliente[i]=cliente[i+1];
    }
    (*contador)--;
}


