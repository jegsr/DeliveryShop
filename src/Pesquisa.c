
#include <stdio.h>
#include "estrutura.h"
#include "Produto.h"
#include "LP_Leitura.h"
#include "LP_Utils.h"
#include "Encomenda.h"
#include "Funcionario.h"
#include "FuncoesGerais.h"

#define CONDICAO_IF if(estado_procurado != 4 )

void pesquisarID_Produto(PRODUTO produto[], unsigned int contador) {
    unsigned int id_procurado;
    int indice;


    readInt(&id_procurado, MINIMO_ID, MAXIMO_ID, "ID do produto a pesquisar: ");


    if ((indice = encontrarID_Produto(id_procurado, produto, contador)) != -1) {
        listar_Produto(produto[indice]);
    } else {
        PRINT_ID_INVALIDO;
    }
}

void pesquisarPreco_Produto(PRODUTO produto[], unsigned int contador) {
    float preco_procurado;
    int i, listado = 0;


    readFloat(&preco_procurado, MINIMO_PRECO, MAXIMO_PRECO, "Preco a pesquisar: ");


    for (i = 0; i < contador; i++) {
        if (produto[i].preco <= preco_procurado) {
            listar_Produto(produto[i]);
            listado++;
        }
    }

    if (listado == 0)
        PRINT_PESQUISA_INVALIDO;
}

void pesquisar_EstadoEncomenda(ENCOMENDA encomenda[], unsigned const int contador) {
    unsigned int estado_procurado;


    readInt(&estado_procurado, 1, 4, "\n( 1=Pendente\t 2=Aprovado\t 3=Entregue\t 4=Todos\t )\nEstado da Encomenda a procurar: ");


    switch (estado_procurado) {
        case 4:
        case 1:
            listar_Encomendas_Estado(encomenda, contador, PENDENTE);
            CONDICAO_IF
            break;
        case 2:
            listar_Encomendas_Estado(encomenda, contador, APROVADA);
            CONDICAO_IF
            break;
        case 3:
            listar_Encomendas_Estado(encomenda, contador, ENTREGUE);
            CONDICAO_IF
            break;
    }
}

void pesquisar_EncomendaEstado_Cliente(unsigned int id_cliente, ENCOMENDA encomenda[], unsigned int contadorEncomenda) {
    ENCOMENDA encomendaTemp[contadorEncomenda];
    int i, j=0;
    for (i = 0; i < contadorEncomenda; i++) {
        if (id_cliente == encomenda[i].id_cliente) {
            encomendaTemp[j] = encomenda[i];
            j++;
        }
    }

    pesquisar_EstadoEncomenda(encomendaTemp, j);
}

void pesquisarData_Encomenda(ENCOMENDA encomenda[], unsigned int contador) {
    unsigned int i, listado = 0;

    DATA data;
    adicionar_Data(&data);

    for (i = 0; i < contador; i++) {

        if (data.ano == encomenda[i].data_entrega.ano);
        {
            if (data.mes == encomenda[i].data_entrega.mes);
            {
                if (data.dia == encomenda[i].data_entrega.dia);
                {
                    listar_Encomenda(encomenda[i]);
                    listado++;
                }
            }
        }
    }
    if (listado == 0) {
        PRINT_PESQUISA_INVALIDO;
    }
}

void pesquisar_Cliente_Data(ENCOMENDA encomenda[], unsigned int id_cliente, unsigned int contador) {
    ENCOMENDA encomendaTemp[contador];
    int i, j;
    for (i = 0, j = 0; i < contador; i++) {
        if (id_cliente == encomenda[i].id_cliente) {
            encomendaTemp[j] = encomenda[i];
            j++;
        }
    }

    pesquisarData_Encomenda(encomendaTemp, j);
}

void pesqusiar_funcionario_Cargo(FUNCIONARIO funcionario[], unsigned const int contador) {

    unsigned int estado_procurado;


    readInt(&estado_procurado, 1, 5, "\n( 1=Tratamento de encomendas\t 2=Entrega de encomendas\t 3=Gestor\t 4=Todos\t 5=Sair )\nFuncao do funcionario: ");


    switch (estado_procurado) {
        case 4:
        case 1:
            listar_FuncionarioPorCargo(funcionario, contador, TRATAMENTO_ENCOMENDAS);
            CONDICAO_IF
            break;
        case 2:
            listar_FuncionarioPorCargo(funcionario, contador, ENTREGA_ENCOMENDAS);
            CONDICAO_IF
            break;
        case 3:
            listar_FuncionarioPorCargo(funcionario, contador, GESTOR);
            CONDICAO_IF
            break;
        case 5:
            //SAIR
            PRINT_MENU
            printf("A Voltar.....");
            PRINT_MENU
            break;
    }

}