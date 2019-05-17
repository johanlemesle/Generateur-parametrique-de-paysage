#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED
#include "Coords.h"
#include "rectangle.h"
#include "triangle.h"
#include "ellipse.h"
#include <vector>

class Arbre
{
protected :
    Coords m_position;
    Rectangle m_tronc;
    int m_nbrfeuille;
    Couleur m_couleurfeuillage;

public :
    Arbre();
    Arbre(double x,double y);
    virtual ~Arbre() = default;
    Coords getposArbre();
    void setPos(Coords position);
    Rectangle getTronc();
   virtual void dessinerArbre(Svgfile& svgout);
};

#endif // ARBRE_H_INCLUDED
