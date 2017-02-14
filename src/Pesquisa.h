

#ifndef PESQUISA_H
#define PESQUISA_H

#ifdef __cplusplus
extern "C" {
#endif
#include "estrutura.h"

    void pesquisarID_Produto(PRODUTO produto[], unsigned int contador);

    void pesquisarPreco_Produto(PRODUTO produto[], unsigned int contador);

    void pesquisar_EncomendaEstado_Cliente(unsigned int id_cliente, ENCOMENDA encomenda[], unsigned int contadorEncomenda);

    void pesquisarData_Encomenda(ENCOMENDA encomenda[], unsigned int contador);

    void pesquisar_Cliente_Data(ENCOMENDA encomenda[], unsigned int id_cliente, unsigned int contador);

    void pesqusiar_funcionario_Cargo(FUNCIONARIO funcionario[], unsigned const int contador);


#ifdef __cplusplus
}
#endif

#endif /* PESQUISA_H */

