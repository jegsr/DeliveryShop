
#include <stdio.h>
#include <stdlib.h>
#include "Menu_adicionar_admin.h"
#include "Menu_alterar_admin.h"
#include "Menu_eliminar_admin.h"
#include "estrutura.h"
#include "login.h"
#include "ficheiros.h"
#include "Pesquisa.h"
#include "Funcionario.h"
#include "Encomenda.h"
#include "Cliente.h"
#include "Produto.h"
#include "Menu_cliente.h"
#include "FuncoesGerais.h"



void menu_administrador(CLIENTE cliente[], FUNCIONARIO *funcionario, ENCOMENDA encomenda[], USERNAME username[],
        PRODUTO produto[], unsigned int *contadorUsername, unsigned int *contadorCliente,
        unsigned int *contadorFuncionario, unsigned int *contadorEncomenda, unsigned int *contadorProduto, char password[]) {
    unsigned int op;
    do {
        PRINT_MENU
        printf("\t\t\tMENU ADMINISTRADOR\t\t\t");
        PRINT_MENU

        readInt(&op, 1, 6, "\n( 1=Adicionar\t 2=Alterar\t 3=Eliminar\t 4=Listar\t 5=Alterar Password\t 6=Sair\t )\nEscolha uma opcao: ");


        switch (op) {
            case 1:
                menu_adicionar_admin(&cliente[*contadorCliente], &funcionario[*contadorFuncionario],
                        &produto[*contadorProduto], username, contadorProduto, contadorUsername, contadorCliente, contadorFuncionario);
                guardar_ficheiros(cliente, funcionario, username, produto, *contadorCliente, *contadorFuncionario, *contadorUsername, *contadorProduto);
                break;
            case 2:
                menu_alterar_admin(funcionario, cliente, produto, *contadorProduto,
                        *contadorFuncionario, *contadorCliente);
                guardar_ficheiros(cliente, funcionario, username, produto, *contadorCliente, *contadorFuncionario, *contadorUsername, *contadorProduto);
                break;
            case 3:
                menu_eliminar_admin(funcionario,encomenda, produto, cliente, contadorFuncionario,
                        contadorProduto, contadorCliente,contadorEncomenda);
                guardar_ficheiros(cliente, funcionario, username, produto, *contadorCliente, *contadorFuncionario, *contadorUsername, *contadorProduto);
                guardar_ficheiro_encomenda(encomenda,*contadorEncomenda);
                break;
            case 4:menu_listar(produto, encomenda, funcionario, cliente,
                        *contadorCliente, *contadorFuncionario, *contadorEncomenda, *contadorProduto);
                break;
            case 5:
                alterar_Password(password);
                guardar_ficheiro_username(username, *contadorUsername);
                break;
            case 6:PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }
    } while (op != 6);
}

