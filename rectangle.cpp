#include "rectangle.h"

Rectangle::Rectangle(double x, double y, double largeur, double longueur, uint8_t rouge, uint8_t vert, uint8_t bleu) : m_position{x,y}, m_largeur{largeur},m_longueur{longueur},m_couleur{rouge,vert,bleu}
{
}
Rectangle::Rectangle()
{

}
double Rectangle::getLa()
{
    return m_largeur;
}
double Rectangle::getLo()
{
    return m_longueur;
}
void Rectangle::dessinerRect(Svgfile& svgout)
{
    double x = m_position.getX();
    double y = m_position.getY();
    double width = getLa();
    double height = getLo();
    uint8_t r = m_couleur.getR();
    uint8_t v = m_couleur.getV();
    uint8_t b = m_couleur.getB();
    Couleur c(r,v,b);
    svgout.addRectangle(x, y, width, height, c);
}

void Rectangle::dessinerRectMeteo(Svgfile& svgout, Soleil sol)
{

    double width = m_largeur;
    double height = m_longueur;
    std::string col;
    double x1 = m_position.getX();
    double y1 = m_position.getY();
    double x = sol.getSoleil().getPos().getX();
    double y = sol.getSoleil().getPos().getY();
    if(x<200&&x>0)
    {
    col = "deepskyblue";
    svgout.addRectangle(x1, y1, width, height, col);
    }
    if(x<400&&x>200)
    {
    col = "dodgerblue";
    svgout.addRectangle(x1, y1, width, height, col);
    }
    if(x<600&&x>400)
    {
    col = "royalblue";
    svgout.addRectangle(x1, y1, width, height, col);
    }
    if(x<800&&x>400)
    {
    col = "blue";
    svgout.addRectangle(x1, y1, width, height, col);
    }
    if(x<1000&&x>800)
    {
    col = "midnightblue";
    svgout.addRectangle(x1, y1, width, height, col);
    }
    if(x<1200&&x>1000)
    {
        col="Dark";
        svgout.addRectangle(x1, y1, width, height, col);
        svgout.addEllipse(500, 200, 3,3, "yellow");
        for(int i=0; i<200; ++i)
        {
        x=rand()%1000;
        y=rand()%800;
        svgout.addEllipse(x, y, 1, 1, "yellow");
        }
    }
}

Coords Rectangle::getPosition()
{
    return m_position;
}

/*void Rectangle::rotation()
{
    Transformation transfo{Rotation{m_position, 30 }};
    transfo.appliquer(m_position);
}*/
