

#ifndef CRIAR_APROVACAO_H
#define CRIAR_APROVACAO_H

#ifdef __cplusplus
extern "C" {
#endif
#include "estrutura.h"

    void listar_Aprovacao(APROVACAO aprovacao);

    void adicionar_Aprovacao(APROVACAO *aprovacao, unsigned int id_funcionario_trata, unsigned int id_funcionario_entrega);

#ifdef __cplusplus
}
#endif

#endif /* CRIAR_APROVACAO_H */

