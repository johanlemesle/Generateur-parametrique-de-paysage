#ifndef ARBREROND_H_INCLUDED
#define ARBREROND_H_INCLUDED
#include "arbre.h"

class Arbrerond : public Arbre
{
private :
    Ellipse m_feuillagerond;


public :
   virtual void dessinerArbre(Svgfile& svgout);
    Arbrerond(double x,double y,uint8_t r, uint8_t v, uint8_t b);
    ~Arbrerond();
    Ellipse getFeuillageRond();



};


#endif // ARBREROND_H_INCLUDED
