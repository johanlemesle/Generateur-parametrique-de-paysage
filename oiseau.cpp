#include "oiseau.h"

Oiseau::Oiseau(double x, double y,uint8_t r,uint8_t v,uint8_t b) : m_position {x, y}, m_tete{x+8.5,y+2,x+8.5,y-2,x+15.5,y+1.5,r,v,b}, m_corps{x,y,12,3,r,v,b}, m_aile{x-6,y,x+6,y,x-7,y-15,r,v,b}
{}

Ellipse Oiseau::getCorps()
{
    return m_corps;
}

Triangle Oiseau::getAile()
{
    return m_aile;
}

Triangle Oiseau::getTete()
{
    return m_tete;
}

void Oiseau::dessinerOiseau(Svgfile &svgout)
{
    m_tete.dessinerTriangleFill(svgout);
    m_aile.dessinerTriangleFill(svgout);
    m_corps.dessinerEllipseFill(svgout);

}
