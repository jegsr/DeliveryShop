#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "login.h"
#include "LP_Utils.h"
#include "LP_Leitura.h"
#include "estrutura.h"
#include "Menu_admin.h"
#include "Menu_funcionario_aprovar.h"
#include "Menu_funcionario_entrega.h"
#include "Menu_cliente.h"
#include "FuncoesGerais.h"

void verificarTipoLogin(unsigned int id_login, CLIENTE cliente[], FUNCIONARIO funcionario[],
        ENCOMENDA encomenda[], PRODUTO produto[], USERNAME username[], unsigned int *contadorUsername,
        unsigned int *contadorCliente, unsigned int *contadorFuncionario, unsigned int *contadorProduto, unsigned int *contadorEncomenda) {
    unsigned int index;

    //id_login == 0 quer dizer que é o administrador da pagina; Username: admin Password: admin (criados sempre que os ficheiros iniciam)
    if (id_login == 0) {

        menu_administrador(cliente, funcionario, encomenda, username, produto, contadorUsername,
                contadorCliente, contadorFuncionario, contadorEncomenda, contadorProduto, username[id_login].password);

    } else if (index = encontrarID_Cliente(id_login, cliente, *contadorCliente) != -1) {

        menu_Cliente(cliente[index].id_registo, encomenda, produto, contadorEncomenda,
                *contadorProduto, username[id_login].password);

    } else {

        index = encontrarID_Funcionario(id_login, funcionario, *contadorFuncionario);

        switch (funcionario[index].cargo) {
            case 1:
                menu_Funcionario_Aprovar(funcionario[index].id_registo, encomenda, funcionario, *contadorEncomenda, *contadorFuncionario, username[id_login].password);
                break;
            case 2:
                menu_Funcionario_Entrega(funcionario[index].id_registo, encomenda, *contadorEncomenda, username[id_login].password);
                break;
            case 3:
                menu_administrador(cliente, funcionario, encomenda, username, produto, contadorUsername,
                        contadorCliente, contadorFuncionario, contadorEncomenda, contadorProduto, username[id_login].password);
                break;
            default:PRINT_USER_INVALIDO;
                break;
        }
    }
}

void menu_login(CLIENTE cliente[], FUNCIONARIO funcionario[],
        ENCOMENDA encomenda[], PRODUTO produto[], USERNAME username[], unsigned int *contadorUsername,
        unsigned int *contadorCliente, unsigned int *contadorFuncionario, unsigned int *contadorProduto,
        unsigned int *contadorEncomenda, unsigned short *tentativaEntrar, bool *BLOQUEIO) {
    unsigned short op;
    int id_login;
    time_t data_atual;

    do {

        PRINT_MENU
        printf("\t\t\t ENTREGA-EM-MAO\t\t\t");
        PRINT_MENU

        readShort(&op, 1, 3, "\n( 1=Registar\t 2=Login\t 3=Sair ) \n Escolha uma opçao: ");

        switch (op) {
            case 1:
                cliente[*contadorCliente] = registar_Cliente(username, contadorUsername);
                (*contadorCliente)++;
                // guardar ficheiros apos a mudança
                guardar_ficheiro_username(username, *contadorUsername);
                guardar_ficheiro_cliente(cliente, *contadorCliente);
                break;
            case 2:

                if ((*tentativaEntrar) < MAXIMO_TENTATIVA) {
                    id_login = login(contadorUsername, username);
                    if (id_login != -1) {


                        verificarTipoLogin(id_login, cliente, funcionario, encomenda,
                                produto, username, contadorUsername, contadorCliente, contadorFuncionario,
                                contadorProduto, contadorEncomenda);


                        *tentativaEntrar = 0;
                    } else {
                        (*tentativaEntrar)++;
                    }
                } else {
                    time(&data_atual);
                    excesso_tentativas(BLOQUEIO, data_atual, tentativaEntrar);
                }
                break;
            case 3:
                PRINT_MENU
                printf("Obrigado! A Sair......");
                PRINT_MENU

                break;
        }

    } while (op != 3);
}