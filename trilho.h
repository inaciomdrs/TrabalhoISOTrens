#ifndef TRILHO_H
#define TRILHO_H
#include "coordenada.h"
#include "semaforo.h"

class Trilho
{
public:
    Trilho(key_t key);
    ~Trilho();

    Coordenada getCoordenadaInicial();
    Coordenada getCoordenadaFinal();

    void setCoordenadaInicial(int x, int y);
    void setCoordenadaFinal(int x, int y);

    void bloquearTrilho();
    void liberarTrilho();

private:

    Semaforo   *semaforo;
    Coordenada *inicial;
    Coordenada *final;
};

#endif // TRILHO_H
