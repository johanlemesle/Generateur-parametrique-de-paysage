#include "arbretriangle.h"
#include "arbre.h"

Arbretriangle::~Arbretriangle()
{

}
Arbretriangle::Arbretriangle(double x,double y, uint8_t r, uint8_t v, uint8_t b) : Arbre(x,y),m_feuillage{x-(60*(y*y/640000)), y, x+(60*(y*y/640000)), y, x, y-(175*(y*y/640000)), r, v, b,255,255,255}
{
}

Triangle Arbretriangle::getFeuillage()
{
    return m_feuillage;
}

void Arbretriangle::dessinerArbre(Svgfile&svgout)
{

     for(int i=0; i<m_nbrfeuille; ++i)
    {
        m_feuillage.dessinerTriangleArbre(svgout);
        Coords newpos1(m_feuillage.getPosition1().getX(),m_feuillage.getPosition1().getY()-10.0);
        m_feuillage.setPos1(newpos1);
        Coords newpos2(m_feuillage.getPosition2().getX(),m_feuillage.getPosition2().getY()-10.0);
        m_feuillage.setPos2(newpos2);
        Coords newpos3(m_feuillage.getPosition3().getX(),m_feuillage.getPosition3().getY()-10);
        m_feuillage.setPos3(newpos3);

    }

  m_tronc.dessinerRect(svgout);

}
