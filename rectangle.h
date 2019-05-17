#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "forme.h"
#include "couleur.h"
#include "svgfile.h"
#include "soleil.h"
#include "transformation.h"

class Rectangle
{
    private :
        Coords m_position;
        Couleur m_couleur;
        double m_largeur;
        double m_longueur;
    public :
        Rectangle();
        Rectangle(double x, double y, double largeur, double longueur, uint8_t rouge, uint8_t vert, uint8_t bleu);

        void dessinerRect(Svgfile& svgout);
        void dessinerRectMeteo(Svgfile& svgout, Soleil sol);

        Coords getPosition();
        double getLa();
        double getLo();
};

#endif // RECTANGLE_H_INCLUDED
