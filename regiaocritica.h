#ifndef REGIAOCRITICA_H
#define REGIAOCRITICA_H

#include <QVector>
#include "coordenada.h"
#include "semaforo.h"

class RegiaoCritica
{
public:
    RegiaoCritica(int idSemaforo);
    ~RegiaoCritica();
    void liberarTrilho();
    void bloquearTrilho();
    void adicionarPontoAcesso(int x, int y);
    QVector<Coordenada> listarCoordenadasCriticas();

private:
    QVector<Coordenada> pontos_de_acesso;
    Semaforo *semaforo;
};

#endif // REGIAOCRITICA_H
