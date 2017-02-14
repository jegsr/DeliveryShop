

#ifndef MENU_CLIENTE_H
#define MENU_CLIENTE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "estrutura.h"
    
void pesquisar_Produto(PRODUTO produto[], unsigned const int contadorProduto);

void Ver_Historico(ENCOMENDA encomenda[], unsigned int contador, unsigned int id_cliente);

void Fazer_Encomenda(ENCOMENDA *encomenda, unsigned int *contadorEncomenda, PRODUTO produto[],
        unsigned const int contadorProduto);

void menu_Cliente(unsigned int id_cliente, ENCOMENDA encomenda[], PRODUTO produto[], 
        unsigned int *contadorEncomenda, unsigned const int contadorProduto,char password[]);



#ifdef __cplusplus
}
#endif

#endif /* MENU_CLIENTE_H */

