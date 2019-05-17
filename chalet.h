#ifndef CHALET_H_INCLUDED
#define CHALET_H_INCLUDED
#include "triangle.h"
#include "rectangle.h"
#include "time.h"
#include "svgfile.h"
#include "util.h"
class Chalet
{
private :
    Coords m_position;
    Triangle m_toit;
    Rectangle m_mur, m_porte;
    int m_fenetre;
    ///Svgfile m_forme;
public :
    Chalet();
    Chalet(double x, double y, uint8_t r, uint8_t v, uint8_t b);
    ~Chalet();
    Coords getposChalet();
    void dessinerChalet(Svgfile& svgout);
};


#endif // CHALET_H_INCLUDED
