#include "soleil.h"

Soleil::Soleil(double x, double y) : m_soleil{x, y, 30, 30, 255, 215, 0}
{

}

void Soleil::dessinerSoleil(Svgfile& svgout)
{
    m_soleil.dessinerEllipseFill(svgout);
}

Ellipse Soleil::getSoleil()
{
    return m_soleil;
}
