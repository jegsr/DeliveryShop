#include <stdio.h>
#include "estrutura.h"
#include "Data.h"
#include "Funcionario.h"
#include "FuncoesGerais.h"

void listar_Aprovacao(APROVACAO aprovacao) {

    listar_ID(aprovacao.id_funcionario_trata, FuncionarAprovar);
    listar_ID(aprovacao.id_funcionario_entrega, FuncionarEntrega);

    listar_Data(aprovacao.data_aprovacao, DataProvacao);

    listar_Data(aprovacao.data_prevista, DataPrevista);

}

void adicionar_Aprovacao(APROVACAO *aprovacao, unsigned int id_funcionario_trata, unsigned int id_funcionario_entrega) {

    adicionar_ID(&aprovacao->id_funcionario_trata, id_funcionario_trata);
    adicionar_ID(&aprovacao->id_funcionario_entrega, id_funcionario_entrega);

    Data(DataProvacao);
    adicionar_Data(&aprovacao->data_aprovacao);
    Data(DataPrevista);
    adicionar_Data(&aprovacao->data_prevista);

}

