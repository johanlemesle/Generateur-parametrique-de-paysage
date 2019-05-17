#include "ellipse.h"

Ellipse::Ellipse(double x, double y, double rx, double ry, uint8_t rougefill, uint8_t vertfill, uint8_t bleufill) : m_position{x,y},m_rx{rx},m_ry{ry},m_couleurfill{rougefill,vertfill,bleufill}
{
}
Ellipse::Ellipse(double x, double y, double rx, double ry, uint8_t rougefill, uint8_t vertfill, uint8_t bleufill, uint8_t rougestroke, uint8_t vertstroke, uint8_t bleustroke) : m_position{x,y},m_rx{rx},m_ry{ry},m_couleurfill{rougefill,vertfill,bleufill}, m_couleurstroke{rougestroke,vertstroke,bleustroke}
{
}
Ellipse::Ellipse()
{

}
void Ellipse::dessinerEllipseFill(Svgfile& svgout)
{
    double x = m_position.getX();
    double y = m_position.getY();
    double rx = getRx();
    double ry = getRy();
    uint8_t rf = m_couleurfill.getR();
    uint8_t vf = m_couleurfill.getV();
    uint8_t bf = m_couleurfill.getB();
    Couleur cf(rf,vf,bf);
    svgout.addEllipse(x, y, rx, ry, cf);
}

void Ellipse::dessinerEllipseDegrade(Svgfile& svgout, std::string degrade)
{
    double x = m_position.getX();
    double y = m_position.getY();
    double rx = getRx();
    double ry = getRy();
    svgout.addEllipse(x, y, rx, ry, degrade);
}

void Ellipse::dessinerEllipseStroke(Svgfile& svgout)
{
    double x = m_position.getX();
    double y = m_position.getY();
    double rx = getRx();
    double ry = getRy();
    uint8_t rf = m_couleurfill.getR();
    uint8_t vf = m_couleurfill.getV();
    uint8_t bf = m_couleurfill.getB();
    Couleur cf(rf,vf,bf);
    uint8_t rs = m_couleurstroke.getR();
    uint8_t vs = m_couleurstroke.getV();
    uint8_t bs = m_couleurstroke.getB();
    Couleur cs(rs,vs,bs);
    svgout.addEllipse(x, y, rx, ry, cf, cs);
}

double Ellipse::getRx()
{
    return m_rx;
}
double Ellipse::getRy()
{
    return m_ry;
}
Coords Ellipse::getPos()
{
    return m_position;
}
