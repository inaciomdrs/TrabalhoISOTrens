#include "regiaocritica.h"

RegiaoCritica::RegiaoCritica(int idSemaforo)
{
    semaforo = new Semaforo(idSemaforo,1,0600|IPC_CREAT);
}

RegiaoCritica::~RegiaoCritica()
{
    delete semaforo;
}

void RegiaoCritica::bloquearTrilho(){
    semaforo->P();
}

void RegiaoCritica::liberarTrilho(){
    semaforo->V();
}

void RegiaoCritica::adicionarPontoAcesso(int x, int y){
    Coordenada C(x,y);
    pontos_de_acesso.push_back(C);
}

QVector<Coordenada> RegiaoCritica::listarCoordenadasCriticas(){
    return pontos_de_acesso;
}
