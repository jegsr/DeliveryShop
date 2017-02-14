#include <stdio.h>
#include <stdbool.h>
#include "estrutura.h"
#include "LP_Leitura.h"
#include "LP_Utils.h"
#include <time.h>

void listar_Data(DATA data, char txt[]) {
    printf("Data %s: %hu/%hu/%hu\n", txt, data.dia, data.mes, data.ano);
}

bool verificar_ano_bissexto(unsigned short *ano_bissexto) {
    if (((*ano_bissexto) % 4) == 0);
    if ((*ano_bissexto) % 4 == 0 && (*ano_bissexto) % 100 != 0 || (*ano_bissexto) % 400 == 0)
        return true;
    else
        return false;
}

void verificar_numero_dias(unsigned short *ano, unsigned short *mes, unsigned short *dia) {

    if ((*mes) == 1 || (*mes) == 3 || (*mes) == 5 || (*mes) == 7 || (*mes) == 8 || (*mes) == 10 || (*mes) == 12) {
        readShort(dia, MINIMO_DIAS, MAXIMO_DIAS31, "Dia: ");
    } else
        if ((*mes) == 4 || (*mes) == 6 || (*mes) == 9 || (*mes) == 11) {
        readShort(dia, MINIMO_DIAS, MAXIMO_DIAS30, "Dia: ");
    } else {
        if ((verificar_ano_bissexto(ano)) == true) {
            readShort(dia, MINIMO_DIAS, MAXIMO_DIASBISSEXTO, "Dia: ");
        } else {
            readShort(dia, MINIMO_DIAS, MAXIMO_DIASFEVEREIRO, "Dia: ");
        }
    }
}
bool validar_dataAtual(unsigned const int ano, unsigned const int mes, unsigned const int dia) {
    time_t rawtime;
    struct tm * info;

    time(&rawtime);
    info = localtime(&rawtime);

    if (ano > info->tm_year + 1900 || ano == info->tm_year + 1900 && mes >= info->tm_wday - 1 || ano == info->tm_year + 1900 && mes == info->tm_wday - 1 && dia >= info->tm_mday) {
        return true;
    }

    return false;
}

void adicionar_Mes(unsigned short *mes) {
    readShort(mes, MINIMO_MES, MAXIMO_MES, "Mes: ");
}

void adicionar_Ano(unsigned short *ano) {
    readShort(ano, MINIMO_ANO, MAXIMO_ANO, "Ano: ");
}

void adicionar_Data(DATA * data) {
    bool valido;
    do{
    adicionar_Ano(&data->ano);
    adicionar_Mes(&data->mes);
    verificar_numero_dias(&data->ano, &data->mes, &data->dia);
    
    valido = validar_dataAtual(data->ano,data->mes,data->dia);
    
    if(valido == false){
        printf("\nDATA INFERIOR A ATUAL");
    }
    
    }while(valido == false);

}