

#ifndef MENU_ELIMINAR_H
#define MENU_ELIMINAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "estrutura.h"

    void menu_eliminar_admin(FUNCIONARIO funcionario[], ENCOMENDA encomenda[],PRODUTO produto[], CLIENTE cliente[],
            unsigned int *contadorFuncionario, unsigned int *contadorProduto, unsigned int *contadorCliente, unsigned int *contadorEncomenda);


#ifdef __cplusplus
}
#endif

#endif /* MENU_ELIMINAR_H */

