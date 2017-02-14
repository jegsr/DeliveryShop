#include <stdio.h>
#include "estrutura.h"
#include "LP_Utils.h"
#include "LP_Leitura.h"
#include "login.h"
#include "Produto.h"
#include "ficheiros.h"
#include "FuncoesGerais.h"

void menu_adicionar_admin(CLIENTE *cliente, FUNCIONARIO *funcionario, PRODUTO *produto,
        USERNAME username[], unsigned int *contadorProduto, unsigned int *contadorUsername,
        unsigned int *contadorCliente, unsigned int *contadorFuncionario) {

    unsigned int op;

    PRINT_MENU
    printf("\t\t\tMENU ADMINISTRADOR\t\t\t");
    PRINT_MENU
    readInt(&op, 1, 4, "\n( 1=Funcionario\t 2=Produto\t 3=Cliente\t 4=Sair\t ) \nEscolha uma opcao: ");

    switch (op) {
        case 1:

            *funcionario = registar_Funcionario(username, contadorUsername);
            (*contadorFuncionario)++;

            break;
        case 2:

            adicionar_Produto(produto, *contadorProduto);
            (*contadorProduto)++;

            break;
        case 3:

            *cliente = registar_Cliente(username, contadorUsername);
            (*contadorCliente)++;

            break;
        case 4: PRINT_MENU
            printf("A Voltar.....");
            PRINT_MENU
            break;
    }

}
