

#ifndef CRIAR_INFOMORADA_H
#define CRIAR_INFOMORADA_H

#ifdef __cplusplus
extern "C" {
#endif
#include "estrutura.h"

    void listar_Rua(char rua[]);

    void listar_InfoMorada(INFO_MORADA info_morada);
    
    void adicionar_Rua(char rua[]);

    void adicionar_InfoMorada(INFO_MORADA *info_morada);


#ifdef __cplusplus
}
#endif

#endif /* CRIAR_INFOMORADA_H */

