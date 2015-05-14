#include "trilho.h"

Trilho::Trilho(key_t key)
{
    semaforo = new Semaforo(key,1,0600|IPC_CREAT);
    inicial = new Coordenada();
    final = new Coordenada();
}

Trilho::~Trilho(){
    delete inicial;
    delete final;
    delete semaforo;
}

Coordenada Trilho::getCoordenadaInicial(){

    return *inicial;

}

Coordenada Trilho::getCoordenadaFinal(){

    return *final;

}

void Trilho::setCoordenadaInicial(int x, int y){
    inicial->setX(x);
    inicial->setY(y);
}

void Trilho::setCoordenadaFinal(int x, int y){
    final->setX(x);
    final->setY(y);
}

void Trilho::bloquearTrilho(){
    semaforo->P();
}

void Trilho::liberarTrilho(){
    semaforo->V();
}
