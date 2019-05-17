#ifndef FORME_H_INCLUDED
#define FORME_H_INCLUDED
#include "coords.h"
#include "couleur.h"
class Forme
{
protected :
    Coords m_position;
    Couleur m_couleur;

public :
    Forme(double x,double y, uint8_t rouge, uint8_t vert, uint8_t bleu);
    double getPosition();
    ///virtual ~Forme();
    ///virtual void dessiner();
};

#endif // FORME_H_INCLUDED
