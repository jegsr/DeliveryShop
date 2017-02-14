

#ifndef FUNCIONAR_CLIENTE_H
#define FUNCIONAR_CLIENTE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "estrutura.h"

    void adicionar_Cliente(CLIENTE *cliente);

    void listar_CartaoCredito(char cartao[]);

    void listar_Telefone(char telefone[]);

    void listar_Cliente(CLIENTE cliente);

    void listarTodos_Cliente(CLIENTE cliente[], unsigned const int contador);
    
    void eliminar_Cliente(CLIENTE cliente[], unsigned int *contador, unsigned const int id);
    
#ifdef __cplusplus
}
#endif

#endif /* FUNCIONAR_CLIENTE_H */

