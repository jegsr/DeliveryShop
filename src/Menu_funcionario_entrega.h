



#ifndef MENU_FUNCIONARIO_ENTREGA_H
#define MENU_FUNCIONARIO_ENTREGA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "estrutura.h"

    void ConfirmarEntrega(ENCOMENDA encomenda[], unsigned const int contadorEncomenda,
            unsigned const int id_funcionario);

    void menu_Funcionario_Entrega(unsigned const int id_funcionario, ENCOMENDA encomenda[],
            unsigned const int contadorEncomenda, char password[]);


#ifdef __cplusplus
}
#endif

#endif /* MENU_FUNCIONARIO_ENTREGA_H */

