
#include <stdio.h>
#include "estrutura.h"
#include "LP_Utils.h"
#include "LP_Leitura.h"
#include "Encomenda.h"
#include "ficheiros.h"
#include "FuncoesGerais.h"

void ConfirmarEntrega(ENCOMENDA encomenda[], unsigned const int contadorEncomenda,
        unsigned const int id_funcionario) {
    unsigned int indice_encomenda;
    indice_encomenda = verificarID_EncomendaParaFuncionarioEntrega(encomenda, contadorEncomenda, id_funcionario);
    if (indice_encomenda == -1) {
        PRINT_PESQUISA_INVALIDO;
    } else
        encomenda[indice_encomenda].estado = ENTREGUE;
}

void menu_Funcionario_Entrega(unsigned const int id_funcionario, ENCOMENDA encomenda[],
        unsigned const int contadorEncomenda, char password[]) {

    unsigned int op;

    do {
        PRINT_MENU
        printf("\t\t\tMENU DE CARGO ENTREGA\t\t\t");
        PRINT_MENU


        readInt(&op, 1, 4, "\n( 1=Listar Encomendas Aprovadas\t 2=Confirmar Entrega Encomenda\t 3=Alterar password\t 4=Sair\t )\nEscolha uma opcao: ");


        switch (op) {
            case 1:
                listar_EncomendasAprovadas_FuncionarioEntrega(encomenda, id_funcionario, contadorEncomenda);
                break;
            case 2:
                ConfirmarEntrega(encomenda, contadorEncomenda, id_funcionario);
                guardar_ficheiro_encomenda(encomenda, contadorEncomenda);
                break;
            case 3:
                alterar_Password(password);
                break;
            case 4:PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }
    } while (op != 4);
}


