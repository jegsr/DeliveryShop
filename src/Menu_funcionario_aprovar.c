
#include <stdio.h>
#include "estrutura.h"
#include "LP_Utils.h"
#include "LP_Leitura.h"
#include "Encomenda.h"
#include "Funcionario.h"
#include "login.h"
#include "ficheiros.h"
#include "FuncoesGerais.h"



void AprovarEncomendas(ENCOMENDA encomenda[], FUNCIONARIO funcionario[], unsigned const int id_funcionario,
        unsigned const int contadorEncomenda, unsigned const int contadorFuncionario) {

    unsigned int indice_encomenda, indice_funcionario;


    //garante que so obtenho um indice valido para encomenda
    indice_encomenda = verificarID_EncomendaPorEstado(encomenda, contadorEncomenda, PENDENTE);
    if (indice_encomenda != -1) {
        //garante que o funcionario escolhido para entrega é do respetivo cargo
        indice_funcionario = verificarID_FuncionarioPorCargo(funcionario, contadorFuncionario, ENTREGA_ENCOMENDAS);

        if (indice_funcionario != -1) {

            adicionar_Aprovacao(&encomenda[indice_encomenda].aprovacao, id_funcionario, indice_funcionario);

            adicionar_Custo(&encomenda[indice_encomenda].preco_final);
            // passar a encomenda a aprovada
            encomenda[indice_encomenda].estado = APROVADA;
        } else {
            PRINT_PESQUISA_INVALIDO;
        }
    } else {
        PRINT_PESQUISA_INVALIDO;
    }
}

void ValidarEntrega(ENCOMENDA encomenda[], unsigned const int contadorEncomenda, unsigned const int id_funcionario) {
    unsigned int indice_encomenda;

    //garante que so obtenho um indice valido para encomenda
    indice_encomenda = verificarID_EncomendaParaFuncionarioAprova(encomenda, contadorEncomenda, id_funcionario);
    if (indice_encomenda != -1) {
        adicionar_Data(&encomenda[indice_encomenda].data_entrega);
    } else {
        PRINT_PESQUISA_INVALIDO;
    }
}

void menu_Funcionario_Aprovar(unsigned const int id_funcionario, ENCOMENDA encomenda[], FUNCIONARIO funcionario[],
        unsigned const int contadorEncomenda, unsigned const int contadorFuncionario, char password[]) {

    unsigned int op;
    do {

        PRINT_MENU
        printf("\t\t\tMENU DE CARGO APROVAR\t\t\t");
        PRINT_MENU

        readInt(&op, 1, 7, "\n( 1=Listar Encomendas Pendentes\n 2=Listar Funcionarios de Entrega\n "
                "3=Aprovar Encomendas\n 4= Listar Encomendas Entregues\n 5=Confirmar Entrega Encomenda\n"
                " 6=Alterar password\n 7=Sair\n )\nEscolha uma opcao: ");


        switch (op) {
            case 1:
                //listar as encomendas que necessitam de ser aprovadas
                listar_Encomendas_Estado(encomenda, contadorEncomenda, PENDENTE);
                break;
            case 2:
                // listar só os funcionarios com o cargo respetivo a entrega de encomendas
                listar_FuncionarioPorCargo(funcionario, contadorFuncionario, ENTREGA_ENCOMENDAS);
                break;
            case 3:
                /**
                 * aprovar encomendas escolhendo a encomenda pendente e selecionando o funcionario para entrega.
                 * colocando a data de aprovacao junto com a data prevista. 
                 */
                AprovarEncomendas(encomenda, funcionario, id_funcionario, contadorEncomenda, contadorFuncionario);
                guardar_ficheiro_encomenda(encomenda, contadorEncomenda);
                break;
            case 4://listar encomendas entregues
                listar_EncomendasEntregue_FuncionarioAprovar(encomenda,  id_funcionario,contadorEncomenda);
                break;
            case 5:// validar uma entrega colocando a data de entrega na encomenda
                ValidarEntrega(encomenda, contadorEncomenda, id_funcionario);
                guardar_ficheiro_encomenda(encomenda, contadorEncomenda);
                break;
            case 6://alterar password do utilizador
                alterar_Password(password);
                break;
            case 7:
                //sair
                PRINT_MENU
                printf("A Voltar.....");
                PRINT_MENU
                break;
        }
    } while (op != 7);
}
