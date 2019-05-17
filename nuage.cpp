#include "nuage.h"
#include "util.h"
 Nuage::Nuage(double x, double y) : m_posnuage{x,y}, m_base(0,0,0,0,255,255,255)///: m_base(x,y,90*taille,10*taille,255,255,255), m_taille{taille}
{
    /*creerNuageB(x, y);
    creerNuageN(x, y);*/
}

Coords Nuage::getNuage()
{
    return m_posnuage;
}

double Nuage::getTaille()
{
    return m_taille;
}

void Nuage::setTaille(double taille)
{
    m_taille=taille;
}

void Nuage::creerNuageB(double x, double y, uint8_t r,uint8_t v,uint8_t b)
{
    Rectangle base(x,y,180*(m_taille),20*(m_taille),r,v,b);
    m_base=base;

    Ellipse nb1(x,y+(10*(m_taille)),10*m_taille,10*m_taille,r,v,b);
    m_nuageb.push_back(nb1);

    Ellipse nb2(x+(20*(m_taille)),y,20*m_taille,20*m_taille,r,v,b);
    m_nuageb.push_back(nb2);

    Ellipse nb3(x+(60*(m_taille)),y-(10*(m_taille)),30*m_taille,30*m_taille,r,v,b);
    m_nuageb.push_back(nb3);

    Ellipse nb4(x+(110*(m_taille)),y-(6*(m_taille)),24*m_taille,24*m_taille,r,v,b);
    m_nuageb.push_back(nb4);

    Ellipse nb5(x+(140*(m_taille)),y-(3*(m_taille)),22*m_taille,22*m_taille,r,v,b);
    m_nuageb.push_back(nb5);

    Ellipse nb6(x+(160*(m_taille)),y,20*m_taille,20*m_taille,r,v,b);
    m_nuageb.push_back(nb6);

    Ellipse nb7(x+(180*(m_taille)),y+(10*(m_taille)),10*m_taille,10*m_taille,r,v,b);
    m_nuageb.push_back(nb7);

}
void Nuage::creerNuageN(double x , double y)
{
    Ellipse nn1(x-(2*(m_taille)),y+(10*(m_taille)),10*m_taille,10*m_taille,175,175,175);
    m_nuagen.push_back(nn1);

    Ellipse nn2(x+(18*(m_taille)),y,20*m_taille,20*m_taille,175,175,175);
    m_nuagen.push_back(nn2);

    Ellipse nn3(x+(58*(m_taille)),y-(10*(m_taille)),30*m_taille,30*m_taille,175,175,175);
    m_nuagen.push_back(nn3);

    Ellipse nn4(x+(108*(m_taille)),y-(6*(m_taille)),24*m_taille,24*m_taille,175,175,175);
    m_nuagen.push_back(nn4);

    Ellipse nn5(x+(138*(m_taille)),y-(3*(m_taille)),22*m_taille,22*m_taille,175,175,175);
    m_nuagen.push_back(nn5);

    Ellipse nn6(x+(158*(m_taille)),y,20*m_taille,20*m_taille,175,175,175);
    m_nuagen.push_back(nn6);

    Ellipse nn7(x+(178*(m_taille)),y+(10*(m_taille)),10*m_taille,10*m_taille,175,175,175);
    m_nuagen.push_back(nn7);

}

void Nuage::dessinerNuage(Svgfile& svgout)
{
    m_base.dessinerRect(svgout);
    for(size_t i=0; i<m_nuagen.size(); ++i)
    {
        m_nuagen[i].dessinerEllipseFill(svgout);
    }
    for(size_t i=0; i<m_nuageb.size(); ++i)
    {
        m_nuageb[i].dessinerEllipseFill(svgout);
    }
}
