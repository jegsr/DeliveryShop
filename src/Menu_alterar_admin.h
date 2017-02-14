

#ifndef MENU_ALTERAR_H
#define MENU_ALTERAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "estrutura.h"

    void alterar_funcionario(FUNCIONARIO *funcionario);

    void alterar_cliente(CLIENTE *cliente);

    void alterar_produto(PRODUTO *produto, unsigned const int contador);

    void menu_alterar_admin(FUNCIONARIO funcionario[], CLIENTE cliente[], PRODUTO produto[],
            unsigned int contadorProduto, unsigned int contadorFuncionario, unsigned int contadorCliente);

#ifdef __cplusplus
}
#endif

#endif /* MENU_ALTERAR_H */

