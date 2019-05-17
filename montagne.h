#ifndef MONTAGNE_H_INCLUDED
#define MONTAGNE_H_INCLUDED

#include <iostream>
#include "coords.h"
#include "triangle.h"
#include "svgfile.h"
#include "util.h"

class Montagne
{
private :
    Coords m_position;
    Triangle m_tr1;
    Triangle m_tr2;
    std::string m_color;

public :

    Montagne(double x,double y,std::string color);
    ~Montagne() = default;
    Coords getPosMontagne();
    Triangle getTri1();
    Triangle getTri2();
    void dessinerMontagne(Svgfile& svgout,std::string& color,std::string& color2);
};

#endif // MONTAGNE_H_INCLUDED
