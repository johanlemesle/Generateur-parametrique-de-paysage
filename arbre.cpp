#include "arbre.h"
#include "rectangle.h"
#include "triangle.h"
#include "coords.h"
#include "arbrerond.h"
#include "arbretriangle.h"
#include "ellipse.h"

Arbre::Arbre(double x, double y) : m_position {x, y}, m_tronc{x-(15*(y*y/640000)),y,30*(y*y/640000),30*(y*y/640000),88, 41, 0}, m_nbrfeuille{3}
{

}
Arbre::Arbre()
{

}

Rectangle Arbre::getTronc()
{
    return m_tronc;
}


Coords Arbre::getposArbre()
{
    return m_position;
}

void Arbre::dessinerArbre(Svgfile& svgout)
{
  m_tronc.dessinerRect(svgout);
}

