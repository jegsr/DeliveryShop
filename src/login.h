
#ifndef LOGIN_H
#define LOGIN_H




#ifdef __cplusplus
extern "C" {
#endif
    
#include "estrutura.h"
#include <time.h>
#include <stdbool.h>

    void adicionar_Username(char user[], USERNAME *utilizador);

    void adicionar_Password(char password[], USERNAME *utilizador);
    
    bool verificar_Utilizador(char utilizador[], USERNAME user[], unsigned int contador);

    int verificar_PosicaoUtilizador(char utilizador[], USERNAME user[], unsigned int contador);

    bool verificar_Password(USERNAME user, char password[]);

    void alterar_Password(char password_original[]);

    void registar(USERNAME user[], unsigned int contador);

    CLIENTE registar_Cliente(USERNAME user[], unsigned int *contadorUsername);

    FUNCIONARIO registar_Funcionario(USERNAME user[], unsigned int *contador);

    int login(unsigned int *contador, USERNAME user[]);

    void excesso_tentativas(bool *BLOQUEIO, time_t data_atual, unsigned short *tentativaEntrar);


#ifdef __cplusplus
}
#endif

#endif /* LOGIN_H */

