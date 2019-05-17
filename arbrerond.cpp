#include "arbrerond.h"
#include "arbre.h"

Arbrerond::~Arbrerond()
{

}

Arbrerond::Arbrerond(double x,double y,uint8_t r, uint8_t v, uint8_t b) : Arbre(x,y), m_feuillagerond{x,y-(60*(y*y/640000)),40*(y*y/640000),70*(y*y/640000),r,v,b,0,0,0}
{

}
Ellipse Arbrerond::getFeuillageRond()
{
    return m_feuillagerond;
}
void Arbrerond::dessinerArbre(Svgfile& svgout)
{

        m_tronc.dessinerRect(svgout);
        m_feuillagerond.dessinerEllipseStroke(svgout);

}
