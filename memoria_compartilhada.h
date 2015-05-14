#ifndef MEMORIA_COMPARTILHADA
#define MEMORIA_COMPARTILHADA

#include <string.h>    //strcpy
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>   //shmget
#include <sys/shm.h>   //shmget,shmat
#include <sys/types.h> //shmat

class MemoriaCompartilhada {
private:
    void *data;
    int mem_id;
    void apagar();
public:
    MemoriaCompartilhada(int key, bool criar, int size=1024);
    ~MemoriaCompartilhada();
    void desassociar(bool apagar=false);
    void* getData();
};

#endif // MEMORIA_COMPARTILHADA

