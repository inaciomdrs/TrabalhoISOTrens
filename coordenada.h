#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada
{
public:

    Coordenada();

    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

private:

    int x;
    int y;

};

#endif // COORDENADA_H
