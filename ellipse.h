#ifndef ELLIPSE_H_INCLUDED
#define ELLIPSE_H_INCLUDED
#include "forme.h"
#include "svgfile.h"
#include "transformation.h"

class Ellipse
{
    private :
        Coords m_position;
        Couleur m_couleurfill;
        Couleur m_couleurstroke;
        double m_rx;
        double m_ry;
    public :
        Ellipse();
        Ellipse(double x, double y, double rx, double ry, uint8_t rougefill, uint8_t vertfill, uint8_t bleufill);
        Ellipse(double x, double y, double rx, double ry, uint8_t rougefill, uint8_t vertfill, uint8_t bleufill, uint8_t rougestroke, uint8_t vertstroke, uint8_t bleustroke);

        void dessinerEllipseFill(Svgfile& svgout);
        void dessinerEllipseStroke(Svgfile& svgout);
        void dessinerEllipseDegrade(Svgfile& svgout, std::string degrade);

        double getRx();
        double getRy();

        Coords getPos();
};

#endif // ELLIPSE_H_INCLUDED
