
#ifndef CRIAR_DATA_H
#define CRIAR_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "estrutura.h"
#include <stdbool.h>
    
    void listar_Data(DATA data, char txt[]);
    
    bool verificar_ano_bissexto(unsigned short *ano_bissexto);
    
    void verificar_numero_dias(unsigned short *ano, unsigned short *mes, unsigned short *dia);
     
    void adicionar_Mes( unsigned short *mes);
    
    void adicionar_Ano(unsigned short *ano);
    
    void adicionar_Data(DATA *data);
    
    bool validar_dataAtual(unsigned const int ano, unsigned const int mes, unsigned const int dia);


#ifdef __cplusplus
}
#endif

#endif /* CRIAR_DATA_H */

