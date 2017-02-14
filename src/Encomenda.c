#include <stdio.h>
#include "estrutura.h"
#include "LP_Leitura.h"
#include "LP_Utils.h"
#include "Data.h"
#include "Encomenda.h"
#include "InfoMorada.h"
#include "FuncoesGerais.h"

void adicionar_Custo(float *custoTotal) {
    float preco_servico;
    printf("Custo de Servico");
    adicionar_Preco(&preco_servico);
    
    *custoTotal+=preco_servico;
}

void calcularPrecoFinal(PRODUTO_ENCOMENDA produto_encomenda[], unsigned const int contador_produto, float *preco_final) {
    unsigned int contador;

    for (contador = 0; contador < contador_produto; contador++) {
        (*preco_final) += produto_encomenda[contador].preco_unitario * produto_encomenda[contador].quantidade;
    }
}

void adicionar_Encomenda(ENCOMENDA *encomenda, unsigned int contadorEncomenda, unsigned const int id_cliente) {
    adicionar_ID(&encomenda->id_cliente,id_cliente);
    adicionar_ID(&encomenda->id, contadorEncomenda);
    adicionar_InfoMorada(&encomenda->morada_entrega);
    calcularPrecoFinal(encomenda->produto_encomenda, encomenda->contador_produto, &encomenda->preco_final);
    encomenda->estado = PENDENTE;

}

void listar_Estado(ESTADO estado) {

    switch (estado) {
        case 1: printf("PENDENTE\n", estado);
            break;

        case 2: printf("APROVADO\n", estado);
            break;

        case 3: printf("ENTREGUE\n", estado);
            break;
    }
}

void listar_Encomenda(ENCOMENDA encomenda) {

    listar_ID(encomenda.id, Encomenda);
    listar_ID(encomenda.id_cliente, Cliente);
    listar_InfoMorada(encomenda.morada_entrega);
    listarTodos_ProdutoEncomenda(encomenda.produto_encomenda, encomenda.contador_produto);
    listar_Preco(PrecoFinal, encomenda.preco_final);
    listar_Estado(encomenda.estado);
    listar_Aprovacao(encomenda.aprovacao);
    listar_Data(encomenda.data_entrega, DataEntrega);

}

void listarTodas_Encomenda(ENCOMENDA encomenda[], unsigned const int contador) {
    int i;

    for (i = 0; i < contador; i++) {
        listar_Encomenda(encomenda[i]);
    }
    if (contador == 0)
        PRINT_PESQUISA_INVALIDO;
}

void listar_Encomendas_Estado(ENCOMENDA encomenda[], unsigned const int contadorEncomenda, ESTADO estado) {
    int i = 0;
    while (i < contadorEncomenda) {
        if (encomenda[i].estado == estado) {
            listar_Encomenda(encomenda[i]);
        }
        i++;
    }
    if (contadorEncomenda == 0)
        PRINT_PESQUISA_INVALIDO;

}

void listar_EncomendasAprovadas_FuncionarioEntrega(ENCOMENDA encomenda[], unsigned const int id_funcionario, unsigned const int contadorEncomenda) {
    int i = 0;
    while (i < contadorEncomenda) {
        if (encomenda[i].aprovacao.id_funcionario_entrega == id_funcionario && encomenda[i].estado == APROVADA) {
            listar_Encomenda(encomenda[i]);
        }
        i++;
    }
    if (contadorEncomenda == 0)
        PRINT_PESQUISA_INVALIDO;
}

void listar_EncomendasEntregue_FuncionarioAprovar(ENCOMENDA encomenda[], unsigned const int id_funcionario, unsigned const int contadorEncomenda) {
    int i = 0;
    while (i < contadorEncomenda) {
        if (encomenda[i].aprovacao.id_funcionario_trata == id_funcionario && encomenda[i].estado == ENTREGUE) {
            listar_Encomenda(encomenda[i]);
        }
        i++;
    }
    if (contadorEncomenda == 0)
        PRINT_PESQUISA_INVALIDO;
}

void listar_Encomendas_Cliente(unsigned int id_procurado, ENCOMENDA encomenda[], unsigned int contadorEncomenda) {
    int i;
    double custo = 0;
    for (i = 0; i < contadorEncomenda; i++) {
        if (encomenda[i].id_cliente == id_procurado) {
            listar_Encomenda(encomenda[i]);
            custo += encomenda[i].preco_final;

            printf("\n");
        }

    }

    printf("\nCusto Total das Encomendas: %.2f\n", custo);

    if (contadorEncomenda == 0)
        PRINT_PESQUISA_INVALIDO;

}

void eliminar_Encomenda(ENCOMENDA encomenda[],unsigned int *contadorEncomenda, unsigned const int index){
    int i;
    for (i = index; i < (*contadorEncomenda) - 1; i++) {
        encomenda[i]=encomenda[i+1];
    }
    (*contadorEncomenda)--;  
}