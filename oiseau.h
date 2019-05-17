#ifndef OISEAU_H_INCLUDED
#define OISEAU_H_INCLUDED
#include "ellipse.h"
#include "triangle.h"
#include "coords.h"

class Oiseau
{
private :
    Coords m_position;
    Triangle m_aile;
    Triangle m_tete;
    Ellipse m_corps;

public :
    Oiseau();
    Oiseau(double x,double y, uint8_t r,uint8_t v,uint8_t b);
    //~Oiseau();
    Coords getposOiseau();
    Triangle getAile();
    Triangle getTete();
    Ellipse getCorps();
    void dessinerOiseau(Svgfile& svgout);
};

#endif // OISEAU_H_INCLUDED
