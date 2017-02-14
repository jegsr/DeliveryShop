
#include <stdio.h>
#include <string.h>
#include "estrutura.h"
#include "LP_Leitura.h"
#include "LP_Utils.h"
#include "FuncoesGerais.h"

void adicionar_Cargo(CARGO *cargo) {

    readInt(cargo, 1, 3, "Cargo: ");

}

void adicionar_Funcionario(FUNCIONARIO *funcionario) {

    adicionar_Nome(funcionario->nome);
    adicionar_Cargo(&funcionario->cargo);

}

void listar_Cargo(CARGO cargo) {
    printf("Cargo: ");
    switch (cargo) {
        case 1:printf("Tratar de encomendas\n");
            break;
        case 2:printf("Entrega as encomendas\n");
            break;
        case 3:printf("Gestor\n");
            break;
    }
}

void listar_Funcionario(FUNCIONARIO funcionario) {

    listar_ID(funcionario.id_registo, Funcionario);
    listar_Nome(funcionario.nome, Funcionario);
    listar_Cargo(funcionario.cargo);

}

void listarTodos_Funcionario(FUNCIONARIO funcionario[], unsigned const int contador) {
    int i = 0;
    while (i < contador) {
        listar_Funcionario(funcionario[i++]);
    }
    if (contador == 0)
        PRINT_PESQUISA_INVALIDO;
}

void listar_FuncionarioPorCargo(FUNCIONARIO funcionario[], unsigned const int contador, CARGO cargo) {
    int i = 0;
    while (i < contador) {
        if (funcionario[i].cargo == cargo) {
            listar_Funcionario(funcionario[i]);
        }
        i++;
    }
    if (contador == 0)
        PRINT_PESQUISA_INVALIDO;
}

void eliminar_Funcionario(FUNCIONARIO funcionario[], unsigned int *contador, unsigned const int id) {
    int i;
    for (i = id; i < (*contador) - 1; i++) {
        funcionario[i] = funcionario[i+1];
    }
    (*contador)--;
}