

#ifndef MENU_ADICIONAR_H
#define MENU_ADICIONAR_H



#ifdef __cplusplus
extern "C" {
#endif
#include "estrutura.h"

    void menu_adicionar_admin(CLIENTE *cliente, FUNCIONARIO *funcionario, PRODUTO *produto, USERNAME username[],
            unsigned int *contadorProduto, unsigned int *contadorUsername, unsigned int *contadorCliente, unsigned int *contadorFuncionario);


#ifdef __cplusplus
}
#endif

#endif /* MENU_ADICIONAR_H */

