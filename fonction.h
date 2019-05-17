#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include "svgfile.h"
#include "couleur.h"
#include "svgfile.h"
#include "util.h"
#include "forme.h"
#include "rectangle.h"
#include "ellipse.h"
#include "triangle.h"
#include "montagne.h"
#include "arbrerond.h"
#include "arbretriangle.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include "arbre.h"
#include "nuage.h"
#include "scene.h"
#include "chalet.h"
#include "oiseau.h"
#include "soleil.h"
#include "fonction.h"


int menu ();
int plan();
int modif();
int application();
void creerMontagnes(Svgfile& svgout,int& graine,int& densite, int& choixcouleur);
void creerArbres(Svgfile& svgout,int& graine,uint8_t& r1,uint8_t& v1,uint8_t& b1,uint8_t& r2,uint8_t& v2,uint8_t& b2,int& densite);
void creerChaletsColline1(Svgfile& svgout,int& graine,uint8_t& r,uint8_t& v,uint8_t& b,int& densite);
void creerChaletsColline2(Svgfile& svgout,int& graine,uint8_t& r,uint8_t& v,uint8_t& b,int& densite);
void creerChaletsColline3(Svgfile& svgout,int& graine,uint8_t& r,uint8_t& v,uint8_t& b,int& densite);
void creerOiseaux(Svgfile& svgout,int& graine,uint8_t& r,uint8_t& v,uint8_t& b,int& densite);
void creerNuages(Svgfile& svgout,int& graine,uint8_t& r,uint8_t& v,uint8_t& b,int& densite);



#endif // FONCTION_H_INCLUDED
