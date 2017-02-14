

#ifndef PRODUTO_ENCOMENDA_H
#define PRODUTO_ENCOMENDA_H

#ifdef __cplusplus
extern "C" {
#endif
#include "estrutura.h"

    void listar_Quantidade(unsigned short quantidade);

    void listar_ProdutoEncomenda(PRODUTO_ENCOMENDA produtoEncomenda);

    void listarTodos_ProdutoEncomenda(PRODUTO_ENCOMENDA produtoEncomenda[], unsigned int contador_produtoEncomenda);

    void adicionar_Quantidade(unsigned short *quantidade);

    void adicionar_ProdutoEncomenda(PRODUTO_ENCOMENDA *produtoEncomenda, unsigned int *contador_produtoEncomenda, PRODUTO *produto);


#ifdef __cplusplus
}
#endif

#endif /* PRODUTO_ENCOMENDA_H */

