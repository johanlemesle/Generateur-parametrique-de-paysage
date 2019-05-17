#include "chalet.h"
#include "time.h"
#include "transformation.h"

Chalet::Chalet(double x, double y, uint8_t r, uint8_t v, uint8_t b) :  m_toit{x-15, y+3, x+15, y+3, x, y-23, r, v, b},m_mur{x-10,y,20,20,91,60,17}, m_porte{x-2.5, y+10, 5, 10 , 0, 0, 0},m_position{x,y},m_fenetre{util::alea(0,3)}
{

}

Chalet::~Chalet()
{

}

Coords Chalet::getposChalet()
{
    return m_position;
}

void Chalet::dessinerChalet(Svgfile& svgout)
{
    m_mur.dessinerRect(svgout);
    m_toit.dessinerTriangleFill(svgout);
    svgout.addEllipse(m_position.getX(), m_position.getY()+2.75, 16, 0.75, "black");
    if(m_fenetre==1)
    {
        svgout.addDisk(m_position.getX(),m_position.getY()-5.5,5,Svgfile::makeRGB(173, 79, 9));
    }
    if(m_fenetre==2)
    {
        svgout.addTriangle(m_position.getX()-6,m_position.getY()-1,m_position.getX()+6,m_position.getY()-1,m_position.getX(),m_position.getY()-11.5,Svgfile::makeRGB(173, 79, 9),Svgfile::makeRGB(173, 79, 9));
    }
    if(m_fenetre==3)
    {
        svgout.addRectangle(m_position.getX()-4.5,m_position.getY()-10,9,9,Svgfile::makeRGB(173, 79, 9));
    }
    m_porte.dessinerRect(svgout);
}

