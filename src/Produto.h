

#ifndef CRIAR_PRODUTO_H
#define CRIAR_PRODUTO_H

#ifdef __cplusplus
extern "C" {
#endif
#include "estrutura.h"

    void listar_Produto(PRODUTO produto);

    void listarTodos_Produto(PRODUTO produto[], unsigned int contador_produto);

    void adicionar_Produto(PRODUTO *produto, unsigned int contadorProduto);

    void eliminar_produto(PRODUTO produto[], unsigned int *contador, unsigned const int id);


#ifdef __cplusplus
}
#endif

#endif /* CRIAR_PRODUTO_H */

