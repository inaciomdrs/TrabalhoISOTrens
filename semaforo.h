#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

class Semaforo {
public:
    Semaforo(key_t,int,int);
    ~Semaforo();
    void P();
    void V();
    int getGrupoSemaforos();
    int getContador();
private:
    union sem_num { int val; } arg;
    int grupo_semaforos;
    struct sembuf operacao;
};

#endif // SEMAFORO_H

