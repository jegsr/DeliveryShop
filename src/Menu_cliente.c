

#include <stdio.h>
#include "LP_Utils.h"
#include "LP_Leitura.h"
#include "Pesquisa.h"
#include "estrutura.h"
#include "Encomenda.h"
#include "login.h"
#include "ficheiros.h"
#include "Produto_Encomenda.h"
#include "FuncoesGerais.h"

void pesquisar_Produto(PRODUTO produto[], unsigned const int contadorProduto) {
    unsigned int op;

    do {

        PRINT_MENU
        printf("\t\t\tMENU CLIENTE\t\t\t");
        PRINT_MENU

        readInt(&op, 1, 3, "\n( 1=Pesquisar por ID\t 2=Pesquisar por Preco\t 3=Voltar\t )\nEscolha a opcao: ");


        switch (op) {
            case 1:
                pesquisarID_Produto(produto, contadorProduto);
                break;
            case 2:
                pesquisarPreco_Produto(produto, contadorProduto);
                break;
            case 3:PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }
    } while (op != 3);
}

void Ver_Historico(ENCOMENDA encomenda[], unsigned const int contador, unsigned const int id_cliente) {
    unsigned int op;


    do {
        PRINT_MENU
        printf("\t\t\tMENU CLIENTE\t\t\t");
        PRINT_MENU

        readInt(&op, 1, 4, "\n( 1=Listar Encomendas por Estado\t 2=Listar Encomendas"
                " por Data\t 3=Listar Todas Encomendas \t 4=Voltar\t)\n Escolha a opcao: ");


        switch (op) {
            case 1:
                pesquisar_EncomendaEstado_Cliente(id_cliente, encomenda, contador);
                break;
            case 2:
                pesquisar_Cliente_Data(encomenda, id_cliente, contador);
                break;
            case 3:
                listar_Encomendas_Cliente(id_cliente, encomenda, contador);
                break;
            case 4:PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }
    } while (op != 4);
}

void Fazer_Encomenda(ENCOMENDA *encomenda, unsigned int *contadorEncomenda, PRODUTO produto[],
        unsigned const int contadorProduto, unsigned const int id_cliente) {
    unsigned int indice_produto;
    unsigned short op;

    // introduzir os produtos á encomenda
    do {

        indice_produto = verificarID_Produto(produto, contadorProduto);
        if (indice_produto != -1) {
            adicionar_ProdutoEncomenda(&(encomenda->produto_encomenda[encomenda->contador_produto]),
                    &(encomenda->contador_produto), &produto[indice_produto]);


            readShort(&op, 1, 2, "Pretende encomendar mais algum produto ( 1=Sim 2=Nao ): ");


            if (encomenda->contador_produto == MAXIMO_PRODUTO) {
                PRINT_MAXIMO_PRODUTOS;
            }
        }
    } while (indice_produto != -1 && op != 2 && encomenda->contador_produto < MAXIMO_PRODUTO);

    // finalizar a encomenda
    if(indice_produto != -1){
    adicionar_Encomenda(encomenda, *contadorEncomenda, id_cliente);
    (*contadorEncomenda)++;
    }else{
        PRINT_PESQUISA_INVALIDO;
    }
}

void menu_Cliente(unsigned int id_cliente, ENCOMENDA encomenda[], PRODUTO produto[],
        unsigned int *contadorEncomenda, unsigned const int contadorProduto, char password[]) {
    unsigned int op;
    do {
        PRINT_MENU
        printf("\t\t\tMENU CLIENTE\t\t\t");
        PRINT_MENU

        readInt(&op, 1, 5, "\n( 1=Pesquisar Produto\t 2=Fazer Encomenda\t 3=Ver Historico\t 4=Alterar password\t 5=Sair\t )\nEscolha uma opcao: ");


        switch (op) {
            case 1:
                pesquisar_Produto(produto, contadorProduto);
                break;
            case 2:
                Fazer_Encomenda(&encomenda[*contadorEncomenda], contadorEncomenda, produto, contadorProduto,id_cliente);
                guardar_ficheiro_encomenda(encomenda, *contadorEncomenda);
                break;
            case 3:
                Ver_Historico(encomenda, *contadorEncomenda, id_cliente);
                break;
            case 4:
                alterar_Password(password);
                break;
            case 5:PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }
    } while (op != 5);
}
