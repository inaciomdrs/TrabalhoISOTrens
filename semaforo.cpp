#include "semaforo.h"
#include <iostream>
#include <cstdlib>

#define SEMAFORO_PADRAO_INDEX 0
#define P_OPERATION -1
#define V_OPERATION 1

Semaforo::Semaforo(key_t key, int valorInicial, int flags){
    //Alocando apenas 1 semaforo
    grupo_semaforos = semget(key,1,flags);
    //Verificando erros
    if (grupo_semaforos == -1){
        std::cerr << "Error ao criar semaforo\n";
        exit(1);
    }
    //Modificando o valor da estrutura de configuracao do semaforo
    arg.val = valorInicial;

    //Atualizando o contador do semaforo atraves do comando SETVAL
    semctl(grupo_semaforos,SEMAFORO_PADRAO_INDEX,SETVAL,arg);
}

/*Destrutor
*/

Semaforo::~Semaforo(){
    semctl(grupo_semaforos,SEMAFORO_PADRAO_INDEX,IPC_RMID,arg);
}

void Semaforo::P(){
    operacao.sem_num = SEMAFORO_PADRAO_INDEX; //o grupo é formado por apenas 1 semaforo
    operacao.sem_op = P_OPERATION; //P()
    //Ao finalizar o processo, outros processos que estao pendentes pelo semaforo sao desbloqueados
    operacao.sem_flg = SEM_UNDO;
    semop(grupo_semaforos,&operacao,1);
}

/*
Função utilizada para saida na região critica.
Incrementa o contador do semaforo.
*/

void Semaforo::V(){
    operacao.sem_num = SEMAFORO_PADRAO_INDEX; //o grupo é formado por apenas 1 semaforo
    operacao.sem_op = V_OPERATION; //V()
    //Ao finalizar o processo, outros processos que estao pendentes pelo semaforo sao desbloqueados
    operacao.sem_flg = SEM_UNDO;
    semop(grupo_semaforos,&operacao,1);
}

/*
  Retornar o atributo privado semaforoId
*/
int Semaforo::getGrupoSemaforos(){
  return grupo_semaforos;
}


/*
  Retornar o atributo privado referente ao contador do semaforo
*/
int Semaforo::getContador(){
  return semctl(grupo_semaforos,SEMAFORO_PADRAO_INDEX,GETVAL,arg);
}
