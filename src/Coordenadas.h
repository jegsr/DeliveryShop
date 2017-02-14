

#ifndef CRIAR_COORDENADAS_H
#define CRIAR_COORDENADAS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "estrutura.h"
    
    void listar_coordenada_geral(float latitude, char tipo[]);

    void listar_coordenada(COORDENADAS coordenadas);

    void adicionar_latitude(float *latitude);

    void adicionar_longitude(float *longitude);

    void adicionar_coordenada(COORDENADAS *coordenadas);


#ifdef __cplusplus
}
#endif

#endif /* CRIAR_COORDENADAS_H */

