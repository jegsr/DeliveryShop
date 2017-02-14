

#ifndef CRIAR_CODIGOPOSTAL_H
#define CRIAR_CODIGOPOSTAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "estrutura.h"

    void CodigoPostal_Junto(char cp1[], char cp2[]);
    
    void listar_CodigoPostal(CODIGO_POSTAL codigo_postal);
    
    void CodigoPostal_Geral(char cp[], unsigned int maximo);

    void adicionar_CodigoPostal(CODIGO_POSTAL *codigo_postal);



#ifdef __cplusplus
}
#endif

#endif /* CRIAR_CODIGOPOSTAL_H */

