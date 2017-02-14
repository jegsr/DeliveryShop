

#ifndef CRIAR_ENCOMENDA_H
#define CRIAR_ENCOMENDA_H

#include "estrutura.h"


#ifdef __cplusplus
extern "C" {
#endif


    void calcularPrecoFinal(PRODUTO_ENCOMENDA produto_encomenda[], unsigned int contador_produto, float *preco_final);

    void adicionar_Encomenda(ENCOMENDA *encomenda, unsigned int contadorEncomenda, unsigned const int id_cliente);

    void listar_Estado(ESTADO estado);

    void listar_Encomenda(ENCOMENDA encomenda);

    void listarTodas_Encomenda(ENCOMENDA encomenda[], unsigned const int contador);

    void listar_Encomendas_Estado(ENCOMENDA encomenda[], unsigned const int contadorEncomenda, ESTADO estado);

    void listar_EncomendasAprovadas_FuncionarioEntrega(ENCOMENDA encomenda[], unsigned const int id_funcionario,
            unsigned const int contadorEncomenda);

    void listar_EncomendasEntregue_FuncionarioAprovar(ENCOMENDA encomenda[], unsigned const int id_funcionario,
            unsigned const int contadorEncomenda);
    
    void listar_Encomendas_Cliente(unsigned int id_procurado, ENCOMENDA encomenda[], unsigned int contadorEncomenda);
    
    void adicionar_Custo(float *custoTotal);
    
#ifdef __cplusplus
}
#endif

#endif /* CRIAR_ENCOMENDA_H */

