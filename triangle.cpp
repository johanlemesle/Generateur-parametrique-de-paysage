#include "triangle.h"
#include "coords.h"
#include <iostream>

Triangle::Triangle()
{
}
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3, uint8_t rougefill, uint8_t vertfill, uint8_t bleufill): m_pos1{x1,y1},m_pos2{x2,y2},m_pos3{x3,y3},m_couleurfill{rougefill,vertfill,bleufill},m_couleurstroke{0,0,0}
{
}
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3, uint8_t rougefill, uint8_t vertfill, uint8_t bleufill, uint8_t rougestroke, uint8_t vertstroke, uint8_t bleustroke) : m_pos1{x1,y1},m_pos2{x2,y2},m_pos3{x3,y3},m_couleurfill{rougefill,vertfill,bleufill},m_couleurstroke(rougestroke,vertstroke,bleustroke)
{
}
void Triangle::dessinerTriangleFill(Svgfile& svgout)
{
    double x1 = m_pos1.getX();
    double y1 = m_pos1.getY();
    double x2 = m_pos2.getX();
    double y2 = m_pos2.getY();
    double x3 = m_pos3.getX();
    double y3 = m_pos3.getY();
    uint8_t rf = m_couleurfill.getR();
    uint8_t vf = m_couleurfill.getV();
    uint8_t bf = m_couleurfill.getB();
    Couleur cf(rf,vf,bf);
    svgout.addTriangle(x1, y1, x2, y2, x3, y3, cf);
}

void Triangle::dessinerTriangleStroke(Svgfile& svgout)
{
    double x1 = m_pos1.getX();
    double y1 = m_pos1.getY();
    double x2 = m_pos2.getX();
    double y2 = m_pos2.getY();
    double x3 = m_pos3.getX();
    double y3 = m_pos3.getY();
    uint8_t rf = m_couleurfill.getR();
    uint8_t vf = m_couleurfill.getV();
    uint8_t bf = m_couleurfill.getB();
    Couleur cf(rf,vf,bf);
    uint8_t rs = m_couleurstroke.getR();
    uint8_t vs = m_couleurstroke.getV();
    uint8_t bs = m_couleurstroke.getB();
    Couleur cs(rs,vs,bs);
    svgout.addTriangle(x1, y1, x2, y2, x3, y3, cf, cs);
}


void Triangle::dessinerTriangleDegradeFill(Svgfile& svgout, std::string degrade)
{
    double x1 = m_pos1.getX();
    double y1 = m_pos1.getY();
    double x2 = m_pos2.getX();
    double y2 = m_pos2.getY();
    double x3 = m_pos3.getX();
    double y3 = m_pos3.getY();

    svgout.addTriangle(x1,y1,x2,y2,x3,y3,degrade);
}
void Triangle::dessinerTriangleDegradeStroke(Svgfile& svgout, std::string degrade)
{
    double x1 = m_pos1.getX();
    double y1 = m_pos1.getY();
    double x2 = m_pos2.getX();
    double y2 = m_pos2.getY();
    double x3 = m_pos3.getX();
    double y3 = m_pos3.getY();
    uint8_t rs = m_couleurstroke.getR();
    uint8_t vs = m_couleurstroke.getV();
    uint8_t bs = m_couleurstroke.getB();
    Couleur cs(rs,vs,bs);
    svgout.addTriangle(x1,y1,x2,y2,x3,y3,degrade,cs);
}
void Triangle::setPos1(Coords pos)
{
    m_pos1=pos;
}
void Triangle::setPos2(Coords pos)
{
    m_pos2=pos;
}
void Triangle::setPos3(Coords pos)
{
    m_pos3=pos;
}

void Triangle::dessinerTriangleArbre(Svgfile& svgout)
{
    double x1 = m_pos1.getX();
    double y1 = m_pos1.getY();
    double x2 = m_pos2.getX();
    double y2 = m_pos2.getY();
    double x3 = m_pos3.getX();
    double y3 = m_pos3.getY();
    uint8_t rf = m_couleurfill.getR();
    uint8_t vf = m_couleurfill.getV();
    uint8_t bf = m_couleurfill.getB();
    Couleur cf(rf,vf,bf);
    uint8_t rs = m_couleurstroke.getR();
    uint8_t vs = m_couleurstroke.getV();
    uint8_t bs = m_couleurstroke.getB();
    Couleur cs(rs,vs,bs);
    int nbBoule=util::alea(0,2);
    svgout.addTriangle(x1, y1, x2, y2, x3, y3, cf, cs);
    for(int i=0; i<nbBoule; ++i)
    {
        int var = x2-(x3);
        int xMoit=x3;
        int xT=x1;
        int xDroite = util::alea(xMoit, xMoit+var);
        int xGauche = util::alea(xT, xMoit);
        ///int test = (xDroite-x2)*2.914;
        int test = (xDroite-x2)*2.914;
        int test2 =  (x1-xGauche)*2.914;
        int test1 = util::alea(test, 0);
        int test3 = util::alea(test2, 0);
        double yDroite= y1+test1;
        double yGauche = y1+test3;
        uint8_t r=util::alea(0,255);
        uint8_t v=util::alea(0,255);
        uint8_t b=util::alea(0,255);
        Couleur c ={r,v,b};
        svgout.addEllipse(xDroite, yDroite, 3, 3, c);
        svgout.addEllipse(xGauche, yGauche, 3, 3, c);
    }
}

Coords Triangle::getPosition1()
{
    return m_pos1;
}

Coords Triangle::getPosition2()
{
    return m_pos2;
}

Coords Triangle::getPosition3()
{
    return m_pos3;
}

