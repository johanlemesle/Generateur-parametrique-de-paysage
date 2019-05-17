#ifndef SOLEIL_H_INCLUDED
#define SOLEIL_H_INCLUDED
#include "ellipse.h"
#include "svgfile.h"
class Soleil
{
private :
    Ellipse m_soleil;
public :
    Soleil();
    Soleil(double x, double y);
    void dessinerSoleil(Svgfile& svgout);
    Ellipse getSoleil();
};

#endif // SOLEIL_H_INCLUDED
