




#ifndef MENU_FUNCIONARIO_APROVAR_H
#define MENU_FUNCIONARIO_APROVAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "estrutura.h"
    
void AprovarEncomendas(ENCOMENDA encomenda[], FUNCIONARIO funcionario[], unsigned const int id_funcionario,
        unsigned const int contadorEncomenda, unsigned const int contadorFuncionario);

void ValidarEntrega(ENCOMENDA encomenda[],unsigned const int contadorEncomenda);

void menu_Funcionario_Aprovar(unsigned const int id_funcionario, ENCOMENDA encomenda[], FUNCIONARIO funcionario[],
        unsigned const int contadorEncomenda, unsigned const int contadorFuncionario,char password[]);

#ifdef __cplusplus
}
#endif

#endif /* MENU_FUNCIONARIO_APROVAR_H */

