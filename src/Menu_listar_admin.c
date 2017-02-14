
#include "estrutura.h"
#include <stdio.h>
#include "FuncoesGerais.h"
#include "Pesquisa.h"
#include "Produto.h"
#include "Cliente.h"
#include "Encomenda.h"
#include "Funcionario.h"
#include "LP_Utils.h"
#include "LP_Leitura.h"


void pesquisar_Encomenda(ENCOMENDA encomenda[], unsigned const int contadorEncomenda) {
    unsigned short op;
    unsigned int indice;

    do {
        PRINT_MENU
        printf("\t\t\tMENU ADMINISTRADOR\t\t\t");
        PRINT_MENU
        readShort(&op, 1, 4, "\n( 1=Pesquisar Data\t 2=Pesquisar Estado\t 3=Pesquisar ID\t 4=Sair\t )\nEscolha a opcao: ");

        switch (op) {
            case 1:
                pesquisarData_Encomenda(encomenda, contadorEncomenda);
                break;
            case 2:
                pesquisar_EstadoEncomenda(encomenda, contadorEncomenda);
                break;
            case 3:
                indice = verificarID_Encomenda(encomenda, contadorEncomenda);
                if (indice != -1) {
                    listar_Encomenda(encomenda[indice]);
                }
                break;
            case 4:
                PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }
    } while (op != 4);
}

void pesquisar_Funcionario(FUNCIONARIO funcionario[], unsigned const int contadorFuncionario) {
    unsigned short op;
    unsigned int indice;

    do {
        PRINT_MENU
        printf("\t\t\tMENU ADMINISTRADOR\t\t\t");
        PRINT_MENU
        readShort(&op, 1, 3, "\n( 1=Pesquisar ID\t 2=Pesquisar Cargo\t 3=Voltar\t )\nEscolha a opcao: ");


        switch (op) {
            case 1:

                indice = verificarID_Funcionario(funcionario, contadorFuncionario);
                if (indice != -1)
                    listar_Funcionario(funcionario[indice]);
                break;
            case 2:
                pesqusiar_funcionario_Cargo(funcionario, contadorFuncionario);
                break;
            case 3:PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }
    } while (op != 3);
}

void pesquisar_Cliente(CLIENTE cliente[], unsigned const int contadorCliente) {
    unsigned short op;
    unsigned int indice;

    do {
        PRINT_MENU
        printf("\t\t\tMENU ADMINISTRADOR\t\t\t");
        PRINT_MENU
        readShort(&op, 1, 2, "\n( 1=Pesquisar ID\t 2=Voltar\t )\nEscolha a opcao: ");


        switch (op) {
            case 1:

                indice = verificarID_Cliente(cliente, contadorCliente);
                if (indice != -1)
                    listar_Cliente(cliente[indice]);
                break;

            case 2:PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }

    } while (op != 2);

}

void menu_listar(PRODUTO produto[], ENCOMENDA encomenda[], FUNCIONARIO funcionario[], CLIENTE cliente[],
        unsigned int contadorCliente, unsigned const int contadorFuncionario, unsigned const int contadorEncomenda,
        unsigned const int contadorProduto) {
    unsigned short op;
    do {
        PRINT_MENU
        printf("\t\t\tMENU ADMINISTRADOR\t\t\t");
        PRINT_MENU
        readShort(&op, 1, 9, "\n( 1=Pesquisar Produto\n"
                " 2=Listar Todos Produtos\n"
                " 3=Pesquisar Encomenda\n"
                " 4=Listar Todas Encomendas\n"
                " 5=Pesquisar Funcionario\n"
                " 6=Listar Todos Funcionarios\n"
                " 7=Pesquisar Clientes\n"
                " 8=Listar Todos Clientes\n"
                " 9=Sair\n ) \nEscolha a opcao: ");


        switch (op) {
            case 1:pesquisar_Produto(produto, contadorProduto);
                break;
            case 2:listarTodos_Produto(produto, contadorProduto);
                break;
            case 3:pesquisar_Encomenda(encomenda, contadorEncomenda);
                break;
            case 4:listarTodas_Encomenda(encomenda, contadorEncomenda);
                break;
            case 5:pesquisar_Funcionario(funcionario, contadorFuncionario);
                break;
            case 6:listarTodos_Funcionario(funcionario, contadorFuncionario);
                break;
            case 7:pesquisar_Cliente(cliente, contadorCliente);
                break;
            case 8:listarTodos_Cliente(cliente, contadorCliente);
                break;
            case 9:
                //sair
                PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }


    } while (op != 9);
}

