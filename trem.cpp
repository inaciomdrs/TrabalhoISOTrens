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
    velocidade = 10;
    sleep = 100;

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

        QVector<Coordenada> coordenadas;
        Coordenada C;
        bool quebrou = false;

        switch(ID){
        case 1:
            for (int regiao = 0; regiao < regioesCriticas.size(); ++regiao) {
                coordenadas = regioesCriticas[regiao]->listarCoordenadasCriticas();
                for (int coord = 0; coord < coordenadas.size(); ++coord) {
                    C = coordenadas[coord];

                    if((this->x == C.getX()) && (this->y == C.getY())){
                        if((regiao == 0) && (coord == 0)){
                            regioesCriticas[0]->bloquearTrilho();
                            regioesCriticas[1]->bloquearTrilho();

                            qDebug() << "T1 Bloqueou R1D";
                            qDebug() << "T1 Bloqueou R1BD";

                        } else if((regiao == 0) && (coord == 1)){
                            //regioesCriticas[0]->liberarTrilho();
                            qDebug() << "T1 Liberou R1D";
                        } else if((regiao == 1) && (coord == 1)){
                            regioesCriticas[0]->liberarTrilho();
                            regioesCriticas[1]->liberarTrilho();
                            qDebug() << "T1 Liberou R1D";
                            qDebug() << "T1 Liberou R1BD";
                        }
                    }
                    quebrou = true;
                    break;
                }
                if(quebrou){
                    quebrou = false;
                    break;
                }
            }
            break;
        case 2:
            for (int regiao = 0; regiao < regioesCriticas.size(); ++regiao) {
                coordenadas = regioesCriticas[regiao]->listarCoordenadasCriticas();
                for (int coord = 0; coord < coordenadas.size(); ++coord) {
                    C = coordenadas[coord];

                    if((this->x == C.getX()) && (this->y == C.getY())){
                        if((regiao == 0) && (coord == 3)){
                            regioesCriticas[0]->bloquearTrilho();
                            qDebug() << "T2 Bloqueou R1D";
                        } else if((regiao == 0) && (coord == 2)){
                            regioesCriticas[0]->liberarTrilho();
                            qDebug() << "T2 Liberou R1D";
                        } else if((regiao == 1) && (coord == 0)){
                            regioesCriticas[0]->bloquearTrilho();
                            regioesCriticas[1]->bloquearTrilho();

                            qDebug() << "T2 Bloqueou R1D";
                            qDebug() << "T2 Bloqueou R2BE";
                        } else if((regiao == 1) && (coord == 2)){
                            regioesCriticas[1]->liberarTrilho();
                            qDebug() << "T2 Liberou R2BE";
                        }
                        quebrou = true;
                        break;
                    }
                    if(quebrou){
                        quebrou = false;
                        break;
                    }
                }
            }
            break;
        case 4:
            for (int regiao = 0; regiao < regioesCriticas.size(); ++regiao) {
                coordenadas = regioesCriticas[regiao]->listarCoordenadasCriticas();
                for (int coord = 0; coord < coordenadas.size(); ++coord) {
                    C = coordenadas[coord];

                    if((this->x == C.getX()) && (this->y == C.getY())){
                        if((regiao == 1) && (coord == 2)){
                            regioesCriticas[0]->bloquearTrilho();
                            regioesCriticas[1]->bloquearTrilho();
                            regioesCriticas[2]->bloquearTrilho();

                            qDebug() << "T4 Bloqueou R1D";
                            qDebug() << "T4 Bloqueou R1BD";
                            qDebug() << "T4 Bloqueou R2BE";

                        } else if((regiao == 1) && (coord == 3)){
                            regioesCriticas[0]->liberarTrilho();
                            regioesCriticas[1]->liberarTrilho();
                            qDebug() << "T4 Liberou R1D";
                            qDebug() << "T4 Liberou R1BD";
                        } else if((regiao == 2) && (coord == 1)){
                            regioesCriticas[2]->liberarTrilho();
                            qDebug() << "T4 Liberou R2BE";
                        }
                        quebrou = true;
                        break;
                    }
                    if(quebrou){
                        quebrou = false;
                        break;
                    }
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

void Trem::adicionarRegiaoCritica(RegiaoCritica *regiao){
    regioesCriticas.push_back(regiao);
}
