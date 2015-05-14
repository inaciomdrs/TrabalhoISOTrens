#include "coordenada.h"

Coordenada::Coordenada()
{

}

Coordenada::Coordenada(int xA ,int yA): x(xA), y(yA){}

int Coordenada::getX(){

    return x;
}

int Coordenada::getY(){

    return y;
}

void Coordenada::setX(int x){

    this->x = x;
}

void Coordenada::setY(int y){

    this->y = y;
}
