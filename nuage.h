#ifndef NUAGE_H_INCLUDED
#define NUAGE_H_INCLUDED
#include "ellipse.h"
#include <vector>
#include "rectangle.h"
#include "coords.h"
class Nuage
{
private :
    std::vector<Ellipse> m_nuageb;
    std::vector<Ellipse> m_nuagen;
    Rectangle m_base;
    Coords m_posnuage;
    double m_taille;
public :
    Nuage();
    Nuage(double x, double y);
    ///Nuage(double x, double y);
    void dessinerNuage(Svgfile& svgout);
    void creerNuageB(double x , double y, uint8_t r, uint8_t v, uint8_t b);
    void creerNuageN(double x , double y);
    Coords getNuage();
    double getTaille();
    void setTaille(double taille);
};

#endif // NUAGE_H_INCLUDED
