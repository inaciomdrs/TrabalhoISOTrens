#include "trem.h"
#include <QtCore>


Trem::Trem (int ID, int x, int y, int coordXsup, int coordXdir, int coordXinf, int coordYsup, int coordYdir, int coordYinf){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->coordXsup = coordXsup;
    this->coordXdir = coordXdir;
    this->coordXinf = coordXinf;

    this->coordYsup = coordYsup;
    this->coordYdir = coordYdir;
    this->coordYinf = coordYinf;


    stop = false;
    velocidade = 50;
    sleep = 50;

}

int Trem::getID(){
    return this->ID;
}

int Trem::getX(){
    return this->x;
}

int Trem::getY(){
    return this->y;
}

int Trem::getVelocidade(){
    this->velocidade = 100 - this->sleep;
    if(this->velocidade <= 10){
        this->velocidade = 90;
    }
    return this->velocidade;
}

int Trem::getSleep(){
    return this->sleep;
}

bool Trem::getStop(){
    return this->stop;
}

void Trem::setID(int newID){
    this->ID = newID;
}

void Trem::setStop(bool newStop){
    this->stop = newStop;
}

void Trem::setX(int newX){
    this->x = newX;
}

void Trem::setY(int newY){
    this->y = newY;
}

void Trem::setVelocidade(int newVelocidade){
    this->velocidade = newVelocidade;
}

void Trem::incrementaSleep(){
    this->sleep += 10;
}

void Trem::decrementaSleep(){
    if (this->sleep - 10 < 10){
        this->sleep = 20;
    }else{
        this->sleep -= 10;
    }
}

void Trem::mover(){
    if(y == coordYsup && x < coordXsup)
       x+=10;
    else if(x == coordXdir && y < coordYdir)
       y+=10;
    else if(y == coordYinf && x > coordXinf)
       x-=10;
    else
       y-=10;

//    switch(ID){

//    case 1:
//        if(y == 40 && x < 290)
//            x+=10;
//        } else if(x == 290 && y < 150) {
//            y+=10;
//        } else if(y == 150 && x > 60) {
//            x-=10;
//         else
//            y-=10;
//        break;
//    case 2:
//        if(y == 40 && x < 540)
//            x+=10;
//        else if(x == 540 && y < 150)
//            y+=10;
//        else if(y == 150 && x > 290)
//            x-=10;
//        else
//            y-=10;
//        break;
//    case 3:
//        if(y == 40 && x < 790)
//            x+=10;
//        else if(x == 790 && y < 150)
//            y+=10;
//        else if(y == 150 && x > 540)
//            x-=10;
//        else
//            y-=10;
//        break;
//    case 4:
//        if(y == 150 && x < 400)
//            x+=10;
//        else if(x == 400 && y < 280)
//            y+=10;
//        else if(y == 280 && x > 150)
//            x-=10;
//        else
//            y-=10;
//        break;
//    case 5:
//        if(y == 150 && x < 650)
//            x+=10;
//        else if(x == 650 && y < 280)
//            y+=10;
//        else if(y == 280 && x > 400)
//            x-=10;
//        else
//            y-=10;
//        break;
//    case 6:
//        if(y == 280 && x < 520)
//            x+=10;
//        else if(x == 520 && y < 410)
//            y+=10;
//        else if(y == 410 && x > 290)
//            x-=10;
//        else
//            y-=10;
//        break;
//    default:
//        break;
//    }
}

void Trem::run(){
    while(this->getStop() == false){
        emit updateGUI(ID, x, y);
        mover();

        Coordenada coordenadaInicial;
        Coordenada coordenadaFinal;
        int xI, yI;
        int xF, yF;

        for (int trilho = 0; trilho < regioesCriticas.size(); ++trilho) {
            coordenadaInicial = regioesCriticas[trilho]->getCoordenadaInicial();
            coordenadaFinal = regioesCriticas[trilho]->getCoordenadaFinal();
            xI = coordenadaInicial.getX();
            yI = coordenadaInicial.getY();



        }

        msleep(sleep);
    }
}

void Trem::finalizar()
{
    stop = true;
}

void Trem::adicionarRegiaoCritica(Trilho *regiao){
    regioesCriticas.push_back(regiao);
}
