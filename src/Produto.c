#include <stdio.h>
#include <string.h>
#include "estrutura.h"
#include "FuncoesGerais.h"

void listar_Produto(PRODUTO produto) {

    listar_ID(produto.id, Produto);
    listar_Nome(produto.nome, Produto);
    listar_Preco(PrecoUnitario, produto.preco);

}

void listarTodos_Produto(PRODUTO produto[], unsigned int contador_produto) {
    int contador;

    for (contador = 0; contador < contador_produto; contador++)
        listar_Produto(produto[contador]);

    if (contador_produto == 0)
        PRINT_PESQUISA_INVALIDO;
}

void adicionar_Produto(PRODUTO *produto, unsigned int contadorProduto) {

    adicionar_ID(&produto->id, contadorProduto);
    adicionar_Nome(produto->nome);
    adicionar_Preco(&(produto->preco));


}

void eliminar_Produto(PRODUTO produto[], unsigned int *contador, unsigned const int id) {
    int i;
    for (i = id; i < (*contador) - 1; i++) {
        produto[i]=produto[i+1];
    }
    (*contador)--;
}


