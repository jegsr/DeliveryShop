
#ifndef FUNCOESGERAIS_H
#define FUNCOESGERAIS_H

#ifdef __cplusplus
extern "C" {
#endif

    void adicionar_ID(unsigned int *id, unsigned int contador);

    void listar_ID(unsigned int id, char texto[]);

    void adicionar_Nome(char nome[]);

    void listar_Nome(char nome[],char texto[]);

    void adicionar_Preco(float *preco);

    void listar_Preco(char texto[],float preco);

    bool verificarQuantidadeNumero(char numero[], unsigned const int quantidade);

    void adicionarNumerosChar(char numero[], unsigned const int quantidade);

    int encontrarID_Funcionario(unsigned const int id_procurado, FUNCIONARIO funcionario[], unsigned const int contador);

    int encontrarID_Cliente(unsigned const int id_procurado, CLIENTE cliente[], unsigned const int contador);

    int encontrarID_Produto(unsigned const int id_procurado, PRODUTO produto[], unsigned const int contador);

    int encontrarID_Encomenda(ENCOMENDA encomenda[], unsigned const int id_procurado, unsigned const int contador);

    int encontrarID_EncomendaEstado(unsigned const int id_procurado, ENCOMENDA encomenda[], unsigned const int contador, ESTADO estado);

    int verificarID_EncomendaPorEstado(ENCOMENDA encomenda[], unsigned const int contador, ESTADO estado);

    int encontrarID_EncomendaEstado_E_FuncionarioEntrega(unsigned const int id_procurado, ENCOMENDA encomenda[],
            unsigned const int contador, unsigned const int id_funcionario);

    int verificarID_EncomendaParaFuncionarioEntrega(ENCOMENDA encomenda[], unsigned const int contador, unsigned const int id_funcionario);

    int encontrarID_FuncionarioCargo(unsigned int id_procurado, FUNCIONARIO funcionario[], unsigned int contador, CARGO cargo);

    int verificarID_FuncionarioPorCargo(FUNCIONARIO funcionario[], unsigned int contador, CARGO cargo);

    int encontrarID_EncomendaEstado_E_FuncionarioAprova(unsigned const int id_procurado, ENCOMENDA encomenda[],
            unsigned const int contador, unsigned const int id_funcionario);

    int verificarID_EncomendaParaFuncionarioAprova(ENCOMENDA encomenda[], unsigned int contador, unsigned int id_funcionario);

    int verificarID_Produto(PRODUTO produto[], unsigned const int contador);

    int verificarID_Encomenda(ENCOMENDA encomenda[], unsigned const int contador);

    int verificarID_Funcionario(FUNCIONARIO funcionario[], unsigned int contador);

    int verificarID_Cliente(CLIENTE cliente[], unsigned int contador);




#ifdef __cplusplus
}
#endif

#endif /* FUNCOESGERAIS_H */

