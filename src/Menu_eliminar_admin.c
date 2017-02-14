#include <stdio.h>
#include <string.h>
#include "Produto.h"
#include "Cliente.h"
#include "Funcionario.h"
#include "estrutura.h"
#include "FuncoesGerais.h"
#include "Pesquisa.h"

void menu_eliminar_admin(FUNCIONARIO funcionario[], ENCOMENDA encomenda[], PRODUTO produto[], CLIENTE cliente[],
        unsigned int *contadorFuncionario, unsigned int *contadorProduto, unsigned int *contadorCliente, unsigned int *contadorEncomenda) {
    unsigned int op;
    int temp_id;
    do {
        PRINT_MENU
        printf("\t\t\tMENU ADMINISTRADOR\t\t\t");
        PRINT_MENU

        readInt(&op, 1, 5, "\n( 1=Funcionario\t 2=Produto\t 3=Cliente\t 4=Encomenda\t 5=Voltar\t )\nEscolha uma opcao: ");


        if (op != 5) {

            readInt(&temp_id, MINIMO_ID, MAXIMO_ID, "ID pretendido: ");

        }

        switch (op) {
            case 1:
                //utilizo a mesma variavel para reduzir o gasto de alocaçao, ja que nao necessito da informaçao anterior
                temp_id = encontrarID_Funcionario(temp_id, funcionario, *contadorFuncionario);

                //verificar se o id existe
                if (temp_id != -1)
                    eliminar_Funcionario(funcionario, contadorFuncionario, temp_id);
                else
                    PRINT_ID_INVALIDO;
                break;
            case 2:
                temp_id = encontrarID_Produto(temp_id, produto, *contadorProduto);

                //verificar se o id existe
                if (temp_id != -1)
                    eliminar_Produto(produto, contadorProduto, temp_id);
                else
                    PRINT_ID_INVALIDO;
                break;
            case 3:
                temp_id = encontrarID_Cliente(temp_id, cliente, *contadorCliente);
                //verificar se o id existe
                if (temp_id != -1)
                    eliminar_Cliente(cliente, contadorCliente, temp_id);
                else
                    PRINT_ID_INVALIDO;
                break;
            case 4:
                temp_id = encontrarID_Encomenda(encomenda, temp_id, *contadorEncomenda);
                if (temp_id != -1) {
                    eliminar_Encomenda(encomenda, contadorEncomenda, temp_id);
                } else {
                    PRINT_ID_INVALIDO;
                }
                break;
            case 5:
                //sair
                PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }
    } while (op != 4);
}