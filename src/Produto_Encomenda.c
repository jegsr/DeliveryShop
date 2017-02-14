#include <stdio.h>
#include "LP_Leitura.h"
#include "LP_Utils.h"
#include "estrutura.h"
#include "FuncoesGerais.h"

void listar_Quantidade(unsigned short quantidade) {
    printf("Quantidade: %hu\n", quantidade);
}

void listar_ProdutoEncomenda(PRODUTO_ENCOMENDA produtoEncomenda) {

    listar_ID(produtoEncomenda.id_produto, Produto);
    listar_Quantidade(produtoEncomenda.quantidade);
    listar_Preco(PrecoUnitario, produtoEncomenda.preco_unitario);

}

void listarTodos_ProdutoEncomenda(PRODUTO_ENCOMENDA produtoEncomenda[], unsigned int contador_produtoEncomenda) {
    int contador = 0;

    for (contador = 0; contador < contador_produtoEncomenda; contador++) {
        listar_ProdutoEncomenda(produtoEncomenda[contador]);
    }
}

void adicionar_Quantidade(unsigned short *quantidade) {
    readShort(quantidade, MINIMO_QUANTIDADE, MAXIMO_QUANTIDADE, "Quantidade: ");
}

void adicionar_ProdutoEncomenda(PRODUTO_ENCOMENDA *produtoEncomenda, unsigned int *contador_produtoEncomenda, PRODUTO *produto) {

    adicionar_ID(&(produtoEncomenda->id_produto), produto->id);
    produtoEncomenda->preco_unitario = produto->preco;
    adicionar_Quantidade(&produtoEncomenda->quantidade);
    (*contador_produtoEncomenda)++;

}
