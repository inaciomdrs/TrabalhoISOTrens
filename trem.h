#ifndef TREM_H
#define TREM_H

#include <QThread>

class Trem: public QThread{
    Q_OBJECT
   public:
        Trem(int, int, int);
        void run();
        void finalizar();
        int getX();
        int getY();
        int getID();
        int getVelocidade();
        int getSleep();
        bool getStop();
        void setX(int newX);
        void setY(int newY);
        void setID(int newID);
        void setVelocidade(int newVelocidade);
        void setStop(bool newStop);
        void setSleep(int newSleep);
        void incrementaSleep();
        void decrementaSleep();


   signals:
        void updateGUI(int, int, int);

   private:
        int x;
        int y;
        int ID;
        int sleep;
        int velocidade;
        bool stop;

};

#endif // TREM_H
