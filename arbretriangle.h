#ifndef ARBRETRIANGLE_H_INCLUDED
#define ARBRETRIANGLE_H_INCLUDED

#include "arbre.h"

class Arbretriangle : public Arbre
{
private :
    Triangle m_feuillage;

public :
    virtual void dessinerArbre(Svgfile& svgout);
    Arbretriangle(double x,double y, uint8_t r, uint8_t v, uint8_t b);
    ~Arbretriangle();
    Triangle getFeuillage();



};

#endif // ARBRETRIANGLE_H_INCLUDED
