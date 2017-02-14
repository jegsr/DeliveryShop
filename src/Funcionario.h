

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H


#ifdef __cplusplus
extern "C" {
#endif
    
#include "estrutura.h"
    
void adicionar_Cargo(CARGO *cargo);

void adicionar_Funcionario(FUNCIONARIO *funcionario);

void listar_Cargo(CARGO cargo);

void listar_Funcionario(FUNCIONARIO funcionario);

void listarTodos_Funcionario(FUNCIONARIO funcionario[], unsigned const int contador);

void listar_FuncionarioPorCargo(FUNCIONARIO funcionario[], unsigned const int contador, CARGO cargo);

void eliminar_Funcionario(FUNCIONARIO funcionario[], unsigned int *contador, unsigned const int id);

#ifdef __cplusplus
}
#endif

#endif /* FUNCIONARIO_H */

