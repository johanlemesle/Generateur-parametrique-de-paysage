#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "forme.h"
#include "couleur.h"
#include "svgfile.h"
#include "coords.h"
#include "util.h"
#include "transformation.h"

class Triangle
{
    private :
        Coords m_pos1;
        Coords m_pos2;
        Coords m_pos3;
        Couleur m_couleurfill;
        Couleur m_couleurstroke;
    public :
        Triangle();
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3, uint8_t rougefill, uint8_t vertfill, uint8_t bleufill);
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3, uint8_t rougefill, uint8_t vertfill, uint8_t bleufill, uint8_t rougestroke, uint8_t vertstroke, uint8_t bleustroke);

        Coords getPosition1();
        Coords getPosition2();
        Coords getPosition3();

        void setPos1(Coords pos);
        void setPos2(Coords pos);
        void setPos3(Coords pos);

        void dessinerTriangleFill(Svgfile& svgout);
        void dessinerTriangleStroke(Svgfile& svgout);

        void dessinerTriangleDegradeFill(Svgfile& svgout, std::string degrade);
        void dessinerTriangleDegradeStroke(Svgfile& svgout, std::string degrade);

        void dessinerTriangleArbre(Svgfile& svgout);
};


#endif // TRIANGLE_H_INCLUDED
