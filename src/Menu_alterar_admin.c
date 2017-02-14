#include <stdio.h>
#include <stdlib.h>
#include "LP_Leitura.h"
#include "LP_Utils.h"
#include "estrutura.h"
#include "FuncoesGerais.h"

void alterar_funcionario(FUNCIONARIO *funcionario) {
    unsigned int op;

    PRINT_MENU
    printf("\t\t\tMENU ADMINISTRADOR\t\t\t");
    PRINT_MENU

    readInt(&op, 1, 4, "\n( 1=Nome\t 2=Cargo\t 3=Tudo\t 4=Sair\t )\nEscolha uma opcao: ");


    switch (op) {
        case 1:
            adicionar_Nome(funcionario->nome);
            break;
        case 2:
            adicionar_Cargo(&funcionario->cargo);
            break;
        case 3:
            adicionar_Funcionario(funcionario);
            break;
        case 4:PRINT_MENU
            printf("A Voltar.....");
            PRINT_MENU
            break;
    }

}

void alterar_cliente(CLIENTE *cliente) {
    unsigned int op;
    unsigned int i;
    do {
        PRINT_MENU
        readInt(&op, 1, 5, "\n( 1=Nome\t 2=Cartao Credito\t 3=Telefone\t 4=Tudo\t 5=Sair\t )\nEscolha uma opcao: ");
        PRINT_MENU

        switch (op) {
            case 1:
                adicionar_Nome(cliente->nome);
                break;
            case 2:
                adicionarNumerosChar(cliente->cartao_credito, MAXIMO_CARTAO_CREDITO);
                break;
            case 3:
                if (cliente->contadorTelefone < MAXIMO_NUMERO_TELEFONE) {
                    adicionarNumerosChar(cliente->telefone[cliente->contadorTelefone - 1], MAXIMO_NUMERO_TELEFONE);
                } else {
                    unsigned int op_temp;

                    PRINT_MENU
                    readInt(&op_temp, 1, 4, " \n( 1=primeiro contacto\t 2=segundo contacto\t 3=Todos contactos\t 4=Voltar\t ) Escolha uma opcao: ");
                    PRINT_MENU

                    switch (op_temp) {
                        case 1:
                            adicionarNumerosChar(cliente->telefone[cliente->contadorTelefone - 2], MAXIMO_NUMERO_TELEFONE);
                            break;
                        case 2:
                            adicionarNumerosChar(cliente->telefone[cliente->contadorTelefone - 1], MAXIMO_NUMERO_TELEFONE);
                            break;
                        case 3:
                            i = 0;
                            while (i < cliente->contadorTelefone) {
                                adicionarNumerosChar(cliente->telefone[i], MAXIMO_NUMERO_TELEFONE);
                                i++;
                            }
                        case 4:PRINT_MENU
                            printf("A Voltar.....");
                            PRINT_MENU
                            break;
                    }
                }

                break;
            case 4:
                adicionar_Cliente(cliente);
                break;
            case 5:PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }
    } while (op != 5);
}

void alterar_produto(PRODUTO *produto, unsigned const int contador) {
    unsigned int op;

    PRINT_MENU
    readInt(&op, 1, 5, "\n( 1=Nome\t 2=Preco\t 3=Tudo\t 4=Sair\t )\nEscolha uma opcao: ");
    PRINT_MENU

    switch (op) {
        case 1:
            adicionar_Nome(produto->nome);
            break;
        case 2:
            adicionar_Preco(&produto->preco);
            break;
        case 3:
            adicionar_Produto(produto, contador);
            break;
        case 4:PRINT_MENU
            printf("A Voltar.....");
            PRINT_MENU
            break;
    }

}

void menu_alterar_admin(FUNCIONARIO funcionario[], CLIENTE cliente[], PRODUTO produto[], unsigned int contadorProduto, unsigned int contadorFuncionario, unsigned int contadorCliente) {
    unsigned int op;
    int temp_id;

    do {
        PRINT_MENU
        readInt(&op, 1, 4, "\n( 1=Funcionario\t 2=Produto\t 3=Cliente\t 4=Sair\t ) \nEscolha uma opcao: ");
        PRINT_MENU

        if (op != 4) {
            readInt(&temp_id, MINIMO_ID, MAXIMO_ID, "ID pretendido: ");
        }
        switch (op) {
            case 1://funcionarios
                temp_id = encontrarID_Funcionario(temp_id, funcionario, contadorFuncionario);
                if (temp_id != -1)
                    alterar_funcionario(&funcionario[temp_id]);
                else
                    PRINT_ID_INVALIDO;
                break;
            case 2://produto
                temp_id = encontrarID_Produto(temp_id, produto, contadorProduto);
                if (temp_id != -1)
                    alterar_produto(&produto[temp_id], temp_id);
                else
                    PRINT_ID_INVALIDO;
                break;
            case 3://cliente
                temp_id = encontrarID_Cliente(temp_id, cliente, contadorCliente);
                if (temp_id != -1)
                    alterar_cliente(&cliente[temp_id]);
                else
                    PRINT_ID_INVALIDO;
                break;
            case 4://sair
                PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }
    } while (op != 4);
}
