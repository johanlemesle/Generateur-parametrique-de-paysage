#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
#include "rectangle.h"
#include "ellipse.h"
#include "util.h"
#include "soleil.h"
#include <random>
class Scene
{
private :
    Rectangle m_scene1;
    Ellipse m_scene21;
    Ellipse m_scene22;
    Ellipse m_scene23;
    Ellipse m_scene3;
    std::mt19937 m_graine;
public :
    Scene();
    Scene(int graine);
    void dessinerScene1(Svgfile& svgout, Soleil sol);
    void dessinerScene2(Svgfile& svgout);
    void dessinerScene21(Svgfile& svgout);
    void dessinerScene22(Svgfile& svgout);
    void dessinerScene23(Svgfile& svgout);
    void dessinerScene3(Svgfile& svgout);
    Rectangle getScene1 ();
    Ellipse getScene21();
    Ellipse getScene22();
    Ellipse getScene23();
    Ellipse getScene3();



};

#endif // SCENE_H_INCLUDED
