

#ifndef MENU_LOGIN_H
#define MENU_LOGIN_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "estrutura.h"
#include <stdbool.h>

void verificarTipoLogin(unsigned int id_login, CLIENTE cliente[], FUNCIONARIO funcionario[],
        ENCOMENDA encomenda[], PRODUTO produto[], USERNAME username[], unsigned int *contadorUsername,
        unsigned int *contadorCliente, unsigned int *contadorFuncionario, unsigned int *contadorProduto, unsigned int *contadorEncomenda);

void menu_login(CLIENTE cliente[], FUNCIONARIO funcionario[],
        ENCOMENDA encomenda[], PRODUTO produto[], USERNAME username[], unsigned int *contadorUsername,
        unsigned int *contadorCliente, unsigned int *contadorFuncionario, unsigned int *contadorProduto,
        unsigned int *contadorEncomenda,unsigned short *tentativaEntrar, bool *BLOQUEIO);


#ifdef __cplusplus
}
#endif

#endif /* MENU_LOGIN_H */

