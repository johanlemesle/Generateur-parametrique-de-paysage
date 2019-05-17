#include "montagne.h"

Montagne::Montagne(double x,double y,std::string color) : m_position{x,y}, m_tr1{x+100,y+200,x-300,y+150,x,y-250,230,230,230},m_tr2{x+100,y+200,x+300,y+150,x,y-250,230,230,230},m_color{"url(#grad2)"}
{

}

void Montagne::dessinerMontagne(Svgfile& svgout,std::string& color,std::string& color2)
{
    svgout.degrade();
    m_tr1.dessinerTriangleDegradeFill(svgout,/*"url(#grad2)"*/color);
    m_tr2.dessinerTriangleDegradeFill(svgout,/*"url(#grad3)"*/color2);
}

Triangle Montagne::getTri1()
{
    return m_tr1;
}

Triangle Montagne::getTri2()
{
    return m_tr2;
}
