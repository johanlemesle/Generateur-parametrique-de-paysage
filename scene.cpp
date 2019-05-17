#include "scene.h"

Scene::Scene() : m_scene1{0,0,1000,800,38, 196, 236},
    m_scene21{util::alea(0.0,112.5), 650,util::alea(400.0,500.0),util::alea(300.0,350.0),util::alea(0,79),util::alea(0,134),util::alea(0,89)},
    m_scene22{util::alea(362.5,612.5), 650,util::alea(400.0,500.0),util::alea(300.0,350.0),util::alea(0,79),util::alea(0,134),util::alea(0,89)},
    m_scene23{util::alea(862.5,1000.0), 650,util::alea(400.0,500.0),util::alea(300.0,350.0),util::alea(0,79),util::alea(0,134),util::alea(0,89)},
    m_scene3{500, 1000, 1500, 500, 225, 206, 154}
{
}

Scene::Scene(int graine) : m_graine{graine},m_scene1{0,0,1000,800,38, 196, 236},m_scene21(util::alea(0.0,112.5,m_graine), 650,util::alea(400.0,500.0,m_graine),util::alea(300.0,350.0,m_graine),util::alea(0,79,m_graine),util::alea(0,134,m_graine),util::alea(0,89,m_graine)),
    m_scene22(util::alea(362.5,612.5,m_graine), 650,util::alea(400.0,500.0,m_graine),util::alea(300.0,350.0,m_graine),util::alea(0,79,m_graine),util::alea(0,134,m_graine),util::alea(0,89,m_graine)),
    m_scene23(util::alea(862.5,1000.0,m_graine), 650,util::alea(400.0,500.0,m_graine),util::alea(300.0,350.0,m_graine),util::alea(0,79,m_graine),util::alea(0,134,m_graine),util::alea(0,89,m_graine)),
    m_scene3(500, 1000, 1500, 500, 225, 206, 154)
{
}

void Scene::dessinerScene1(Svgfile& svgout, Soleil sol)
{
    m_scene1.dessinerRectMeteo(svgout, sol);
    sol.dessinerSoleil(svgout);
}
void Scene::dessinerScene21(Svgfile& svgout)
{
    svgout.degrade();
    m_scene21.dessinerEllipseDegrade(svgout, "url(#grad1)");
}
void Scene::dessinerScene22(Svgfile& svgout)
{
    svgout.degrade();
    m_scene22.dessinerEllipseDegrade(svgout, "url(#Plan3)");
}
void Scene::dessinerScene23(Svgfile& svgout)
{
    svgout.degrade();
    m_scene23.dessinerEllipseDegrade(svgout, "url(#grad1)");
}

void Scene::dessinerScene3(Svgfile& svgout)
{

    m_scene3.dessinerEllipseFill(svgout);
}

Rectangle Scene::getScene1 ()
{
    return m_scene1;
}
Ellipse Scene::getScene21()
{
    return m_scene21;
}
Ellipse Scene::getScene22()
{
    return m_scene22;
}
Ellipse Scene::getScene23()
{
    return m_scene23;
}
Ellipse Scene::getScene3()
{
    return m_scene3;
}

