#ifndef TRILHO_H
#define TRILHO_H
#include "coordenada.h"
#include "semaforo.h"

class Trilho
{
public:
    Trilho();

    Coordenada getCoordenadaInicial();
    Coordenada getCoordenadaFinal();


private:

    Semaforo   *semaforo;
    Coordenada *inicial;
    Coordenada *final;
};

#endif // TRILHO_H
