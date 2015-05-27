#include "trem.h"
#include <QtCore>

Trem::Trem (Semaforo** list, int ID, int x, int y, int coordXsup, int coordXdir, int coordXinf, int coordYsup, int coordYdir, int coordYinf){
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
    velocidade = 10;
    sleep = 100;

    this->lista = list;

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
}

void Trem::run(){
    while(this->getStop() == false){
        emit updateGUI(ID, x, y);

        mover();

        switch(ID){
        case 1:
            if((x == 280) && (y == 40)){ // P1
                lista[0]->P();
                lista[2]->P();
            } else if((x == 130) && (y == 150)){ // Saiu de P3
                lista[2]->V();
                lista[0]->V();
            }

            break;

        case 2:
            if((x == 530) && (y == 40)){ // P2
                lista[1]->P();
                lista[4]->P();
                lista[3]->P();
                lista[0]->P();
            }
            else if((x == 310) && (y == 40)){ // Saiu de P1
                if(lista[1]->getContador() == 0){
                    lista[0]->V();
                    lista[1]->V();
                    lista[3]->V();
                    lista[4]->V();
                }
            }

            break;

        case 3:

            if((x == 660) && (y == 150)){
                lista[5]->P();
                lista[1]->P();
            }
            else if((x == 560) && (y == 40)){
                if(lista[5]->getContador() == 0){
                    lista[1]->V();
                    lista[5]->V();
                }
            }

            break;

        case 4:

            if((x == 150) && (y == 160)){ // Posição inicial
                lista[2]->P();
                lista[3]->P();
                lista[6]->P();
                lista[7]->P();
            }
            else if ((x == 280) && (y == 280)){ // Saiu de P8
                if(lista[2]->getContador() == 0){
                    lista[2]->V();
                    lista[3]->V();
                    lista[6]->V();
                    lista[7]->V();
                }
            }

            break;

        case 5:

            if((x == 530) && (y == 280)){ // Posição inicial
                lista[8]->P();
                lista[6]->P();
                lista[4]->P();
                lista[5]->P();
            }
            else if((x == 650) && (y == 170)){ // Posição inicial
                if(lista[8]->getContador() == 0){
                    lista[8]->V();
                    lista[6]->V();
                    lista[4]->V();
                    lista[5]->V();
                }
            }

            break;

        case 6:

            if((x == 290) && (y == 290)){ // Posição inicial
                lista[7]->P();
                lista[8]->P();
            }
            else if((x == 520) && (y == 300)){ // Posição inicial
                if(lista[7]->getContador() == 0){
                    lista[8]->V();
                    lista[7]->V();
                }
            }

            break;
        }
        msleep(sleep);
    }
}

void Trem::finalizar()
{
    stop = true;
}
