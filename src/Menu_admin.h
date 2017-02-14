

#ifndef MENU_ADMIN_H
#define MENU_ADMIN_H

#ifdef __cplusplus
extern "C" {
#endif
#include "estrutura.h"

void menu_administrador(CLIENTE cliente[], FUNCIONARIO *funcionario, ENCOMENDA encomenda[], USERNAME username[],
        PRODUTO produto[], unsigned int *contadorUsername, unsigned int *contadorCliente, 
        unsigned int *contadorFuncionario, unsigned int *contadorEncomenda, unsigned int *contadorProduto,char password[]);

#ifdef __cplusplus
}
#endif

#endif /* MENU_ADMIN_H */

