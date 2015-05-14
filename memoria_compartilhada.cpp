#include "memoria_compartilhada.h"

MemoriaCompartilhada::MemoriaCompartilhada(int key, bool criar, int size){
    mem_id = 0;

    if(criar){
        mem_id = shmget(key,size,0666 | IPC_CREAT);

        if(mem_id == -1){
            printf("ERRO! Não foi possível criar a memória compartilhada!\n");
            exit(EXIT_FAILURE);
        }

    } else {
        mem_id = key;
    }

    data = shmat(mem_id,0,0);

    if(data == (void*) -1){
        printf("ERRO! Não foi possível criar a memória compartilhada! (Falha na associação) \n");
        exit(EXIT_FAILURE);
    }

}

MemoriaCompartilhada::~MemoriaCompartilhada(){
    desassociar();
}

void* MemoriaCompartilhada::getData(){
    return data;
}

void MemoriaCompartilhada::desassociar(bool apagar){
    int x = shmdt(data);
    if(x == -1){
        printf("ERRO! Falha na desassociação!\n");
        exit(EXIT_FAILURE);
    }

    if(apagar){
        x = shmctl(mem_id,IPC_RMID,NULL);
        if(x == -1){
            printf("ERRO! Falha no apagamento da memória compartilhada!\n");
            exit(EXIT_FAILURE);
        }
    }
}
