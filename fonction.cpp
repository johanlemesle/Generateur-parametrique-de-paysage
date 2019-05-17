#include "fonction.h"

int menu() ///Menu utilisateur à finir de compléter en fonction des différents objets que nous allons modifier
{
    int choix;
    std::cout<< "Que voulez vous faire ? " << std::endl;
    std::cout<< "1. Modifier un plan " << std::endl;
    std::cout<< "2. Dessiner votre scene " <<std::endl;
    std::cout<< "3. Sortir " << std::endl;
    std::cout << "Choix : ";
    std::cin>> choix;

    return choix;
}
int plan()
{
    int choix_plan;
    std::cout<< "Quel plan choisissez-vous " << std::endl;
    std::cout<< "1. foret" << std::endl;
    std::cout<< "2. collines / chalets" <<std::endl;
    std::cout<< "3. nuages / oiseaux" <<std::endl;
    std::cout<< "4. montagnes" <<std::endl;
    std::cout << "Choix : ";

    std::cin>> choix_plan;

    return choix_plan;
}
int modif()
{
    int choix_modif;
    std::cout<<"Que voulez-vous modifier sur ce plan"<<std::endl;
    std::cout<<"1. graine"<<std::endl;
    std::cout<<"2. densite"<<std::endl;
    std::cout<<"3. couleur"<<std::endl;
    std::cout << "Choix : ";

    std::cin>> choix_modif;

    return choix_modif;
}
void creerMontagnes(Svgfile& svgout,int& graine,int& densite, int& choixcouleur)
{
    //if(graine==0)
    std::mt19937 realGraine{graine};
    std::string couleur;
    std::string couleur2;
  //  color = {"url(#grad2)"};
    if(choixcouleur==1)
    {
        couleur={"url(#grad4)"};
        couleur2={"url(#grad5)"};
    }
    else if(choixcouleur==2)
    {
        couleur={"url(#grad6)"};
        couleur2={"url(#grad7)"};
    }
    else if(choixcouleur==3)
    {
        couleur={"url(#grad8)"};
        couleur2={"url(#grad9)"};
    }
    else if(choixcouleur==4)
    {
        couleur={"url(#grad10)"};
        couleur2={"url(#grad11)"};
    }
    else if(choixcouleur==5)
    {
        couleur={"url(#grad12)"};
        couleur2={"url(#grad13)"};
    }
    else if(choixcouleur==6)
    {
        couleur={"url(#grad14)"};
        couleur2={"url(#grad15)"};
    }
    else
    {
        couleur={"url(#grad2)"};
        couleur2={"url(#grad3)"};
    }
    int x,y;
    for(int i = 0; i<densite; ++i)
    {
        if(graine==0)
        {
            x=util::alea(0,1000);
            y=util::alea(400,500);
        }
        else
        {
            x=util::alea(0,1000,realGraine);
            y=util::alea(400,500,realGraine);
        }
        Montagne m(x,y,couleur);
        m.dessinerMontagne(svgout,couleur,couleur2);
    }
}
void creerArbres(Svgfile& svgout,int& graine,uint8_t& r1,uint8_t& v1,uint8_t& b1,uint8_t& r2,uint8_t& v2,uint8_t& b2,int& densite)
{
    std::vector <Arbre*>tabA;
    std::mt19937 realGraine{graine};
    int x,y,x1,y1;
    for (int i=0; i<densite; ++i)
    {
        if(graine==0)
        {
            x=util::alea(0,1000);
            y=util::alea(550,770);
            x1=util::alea(0,1000);
            y1=util::alea(550,770);

        }
        else
        {
            x=util::alea(0,1000,realGraine);
            y=util::alea(550,770,realGraine);
            x1=util::alea(0,1000,realGraine);
            y1=util::alea(550,770,realGraine);
        }
        tabA.push_back(new Arbrerond(x,y,r1,v1,b1));
        tabA.push_back(new Arbretriangle(x1,y1,r2,v2,b2));
    }
    for(double i=550; i<770; ++i)
    {
        for(auto& a : tabA)
        {
            if(a->getposArbre().getY() == i) /// Pas de chevauchement (un sapin plus loin sera caché par sapin plus proche) --> on pose les arbres dans l'ordre du plus loin (y petit =550) au plus proche (y grand =770)
                a->dessinerArbre(svgout);
        }
    }
    for(auto& pr : tabA)
        delete pr;
}
void creerChaletsColline1(Svgfile& svgout,int& graine,uint8_t& r,uint8_t& v,uint8_t& b,int& densite)
{
    int x,y;
    std::mt19937 realGraine{graine};
    std::vector <Chalet>tabC21;
    Scene a(graine);
    for (int i=0; i<densite; ++i)
    {
        if(graine==0)
        {
            x=util::alea(a.getScene21().getPos().getX()-a.getScene21().getRx()+200,a.getScene21().getPos().getX()+a.getScene21().getRx()-200);
            y=util::alea(380,480);
        }
        else
        {
            x=util::alea(a.getScene21().getPos().getX()-a.getScene21().getRx()+200,a.getScene21().getPos().getX()+a.getScene21().getRx()-200,realGraine);
            y=util::alea(380,480,realGraine);
        }
        Chalet c(x,y,r,v,b);
        tabC21.push_back(c);
    }
    for(double i=0; i<800; ++i)
    {
        for(double j=0; j<tabC21.size(); ++j)
        {
            if(tabC21[j].getposChalet().getY() == i) /// Pas de chevauchement (un sapin plus loin sera caché par sapin plus proche) --> on pose les arbres dans l'ordre du plus loin (y petit =550) au plus proche (y grand =770)
                tabC21[j].dessinerChalet(svgout);
        }
    }

}
void creerChaletsColline2(Svgfile& svgout,int& graine,uint8_t& r,uint8_t& v,uint8_t& b,int& densite)
{
    int x,y;
    std::mt19937 realGraine{graine};
    std::vector <Chalet>tabC22;
    Scene a(graine);
    for (int i=0; i<densite; ++i)
    {
        if(graine==0)
        {
            x=util::alea(a.getScene22().getPos().getX()-a.getScene22().getRx()+200,a.getScene22().getPos().getX()+a.getScene22().getRx()-200);
            y=util::alea(380,480);
        }
        else
        {
            x=util::alea(a.getScene22().getPos().getX()-a.getScene22().getRx()+200,a.getScene22().getPos().getX()+a.getScene22().getRx()-200,realGraine);
            y=util::alea(380,480,realGraine);
        }
        Chalet c(x,y,r,v,b);
        tabC22.push_back(c);

    }
    for(double i=0; i<800; ++i)
    {
        for(double j=0; j<tabC22.size(); ++j)
        {
            if(tabC22[j].getposChalet().getY() == i) /// Pas de chevauchement (un sapin plus loin sera caché par sapin plus proche) --> on pose les arbres dans l'ordre du plus loin (y petit =550) au plus proche (y grand =770)
                tabC22[j].dessinerChalet(svgout);
        }
    }

}
void creerChaletsColline3(Svgfile& svgout,int& graine,uint8_t& r,uint8_t& v,uint8_t& b,int& densite)
{
    int x,y;
    std::mt19937 realGraine{graine};
    std::vector <Chalet>tabC23;
    Scene a(graine);

    for (int i=0; i<densite; ++i)
    {
        if(graine==0)
        {
            x=util::alea(a.getScene23().getPos().getX()-a.getScene23().getRx()+200,a.getScene23().getPos().getX()+a.getScene23().getRx()-200);
            y=util::alea(380,480);
        }
        else
        {
            x=util::alea(a.getScene23().getPos().getX()-a.getScene23().getRx()+200,a.getScene23().getPos().getX()+a.getScene23().getRx()-200,realGraine);
            y=util::alea(380,480,realGraine);
        }
        Chalet c(x,y,r,v,b);
        tabC23.push_back(c);

    }
    for(double i=0; i<800; ++i)
    {
        for(double j=0; j<tabC23.size(); ++j)
        {
            if(tabC23[j].getposChalet().getY() == i) /// Pas de chevauchement (un sapin plus loin sera caché par sapin plus proche) --> on pose les arbres dans l'ordre du plus loin (y petit =550) au plus proche (y grand =770)
                tabC23[j].dessinerChalet(svgout);
        }
    }

}
void creerOiseaux(Svgfile& svgout, int& graine,uint8_t& r,uint8_t& v,uint8_t& b,int& densite)
{
    int x,y;
    std::mt19937 realGraine{graine};
    for (int i=0; i<densite; ++i)
    {
        if(graine==0)
        {
            x=util::alea(0,1000);
            y=util::alea(10,300);
        }
        else
        {
            x=util::alea(0,1000,realGraine);
            y=util::alea(10,300,realGraine);
        }
        Oiseau o (x, y, r, v, b);
        o.dessinerOiseau(svgout);
    }

}
void creerNuages(Svgfile& svgout, int& graine,uint8_t& r,uint8_t& v,uint8_t& b, int& densite)
{
    std::vector <Nuage>tabN;
    std::mt19937 realGraine{graine};
    int x,y;
    for (int i=0 ; i<densite; ++i)
    {
        if(graine==0)
        {
            x=util::alea(0,1000);
            y=util::alea(0,350);
        }
        else
        {
            x=util::alea(0,1000,realGraine);
            y=util::alea(0,350,realGraine);
        }
        Nuage b (x, y);
        tabN.push_back(b);
    }

    for(double i=100; i<400; ++i)
    {
        for(size_t j=0; j<tabN.size(); ++j)
            if(tabN[j].getNuage().getY() == i)/// Pas de chevauchement (un sapin plus loin sera caché par sapin plus proche) --> on pose les arbres dans l'ordre du plus loin (y petit =550) au plus proche (y grand =770)
            {
                tabN[j].setTaille(150/i);
                tabN[j].creerNuageB(tabN[j].getNuage().getX(),tabN[j].getNuage().getY(),r,v,b);
                tabN[j].creerNuageN(tabN[j].getNuage().getX(),tabN[j].getNuage().getY());

                ///std::cout << tabN[j].getPosition().getY() << " , " << std::endl;
                ///std::cout << tabN[j].getTaille() << " + " ;

                tabN[j].dessinerNuage(svgout);
            }
    }
}
int application()
{
    int densiteMontagnes = 5;
    int densiteOiseaux = 5;
    int densiteNuages = 7;
    int densiteChalets1 = 10;
    int densiteChalets2 = 10;
    int densiteChalets3 = 10;
    int densiteArbres = 30;

    int graine1=0;
    int graine2=0;
    int graine3=0;
    int graine4=0;

    uint8_t r1=17;
    uint8_t v1=127;
    uint8_t b1=64;

    uint8_t r2=9;
    uint8_t v2=82;
    uint8_t b2=40;

    uint8_t rc1=64;
    uint8_t vc1=64;
    uint8_t bc1=64;

    uint8_t rc2=64;
    uint8_t vc2=64;
    uint8_t bc2=64;

    uint8_t rc3=64;
    uint8_t vc3=64;
    uint8_t bc3=64;

    uint8_t rn=255;
    uint8_t vn=255;
    uint8_t bn=255;

    uint8_t ro=0;
    uint8_t vo=0;
    uint8_t bo=0;
    int couleur;
    int choixgradient;

    int choix,choix2,choix3;
    do
    {
        choix = menu();
        switch(choix)
        {
        case 1 :
        {
            choix2 = plan();
            switch(choix2)
            {
            case 1 :
            {
                choix3 = modif();
                switch(choix3)
                {

                case 1 :
                {
                    std::cout<<"Quelle valeur de graine pour la foret?"<<std::endl;
                    std::cin>>graine1;
                    system("cls");
                    std::cout<<std::endl;
                }
                break;
                case 2 :
                {
                    std::cout<<"Valeur de densite d arbres ?" <<std::endl;
                    std::cin>>densiteArbres;
                    system("cls");
                    std::cout<<std::endl;
                }
                break;
                case 3 :
                {
                    std::cout<<"Quelle couleur pour les sapins?" << std::endl;
                    std::cout<<"Dosage en rouge(0-255):" << std::endl;
                    std::cin>>couleur;
                    r1=couleur;
                    std::cout<<"Dosage en vert(0-255):" << std::endl;
                    std::cin>>couleur;
                    v1=couleur;
                    std::cout<<"Dosage en bleu(0-255):" << std::endl;
                    std::cin>>couleur;
                    system("cls");
                    b1=couleur;
                    std::cout<<std::endl;

                    std::cout<<"Quelle couleur pour les arbres fastigies?" << std::endl;
                    std::cout<<"Dosage en rouge(0-255):" << std::endl;
                    std::cin>>couleur;
                    ///system("cls");
                    r2=couleur;
                    std::cout<<"Dosage en vert(0-255):" << std::endl;
                    std::cin>>couleur;
                    ///system("cls");
                    v2=couleur;
                    std::cout<<"Dosage en bleu(0-255):" << std::endl;
                    std::cin>>couleur;
                    system("cls");
                    b2=couleur;
                    std::cout<<std::endl;
                }
                break;
                default:
                    break;
                }
            }
            break;
            case 2 :
            {
                choix3 = modif();
                switch(choix3)
                {

                case 1 :
                {
                    std::cout<<"Quelle valeur de graine pour les villages ?"<<std::endl;
                    std::cin>>graine2;
                    system("cls");
                    std::cout<<std::endl;
                }
                break;
                case 2 :
                {
                    std::cout<<"Valeur de densite pour le village americain ?" <<std::endl;
                    std::cin>>densiteChalets1;
                    system("cls");
                    std::cout<<std::endl;
                    std::cout<<"Valeur de densite pour le village francais ?" <<std::endl;
                    std::cin>>densiteChalets2;
                    system("cls");
                    std::cout<<std::endl;
                    std::cout<<"Valeur de densite pour le village chinois ?" <<std::endl;
                    std::cin>>densiteChalets3;
                    std::cout<<std::endl;
                    system("cls");
                }
                break;
                case 3 :
                {
                    std::cout<<"Quelle couleur pour les toits des chalets americains ?" << std::endl;
                    std::cout<<"Dosage en rouge(0-255):" << std::endl;
                    std::cin>>couleur;
                    ///system("cls");
                    rc1=couleur;
                    std::cout<<"Dosage en vert(0-255):" << std::endl;
                    std::cin>>couleur;
                    ///system("cls");
                    vc1=couleur;
                    std::cout<<"Dosage en bleu(0-255):" << std::endl;
                    std::cin>>couleur;
                    system("cls");
                    bc1=couleur;
                    std::cout<<std::endl;
                    std::cout<<"Quelle couleur pour les toits des chalets francais ?" << std::endl;
                    std::cout<<"Dosage en rouge(0-255):" << std::endl;
                    std::cin>>couleur;
                    ///system("cls");
                    rc2=couleur;
                    std::cout<<"Dosage en vert(0-255):" << std::endl;
                    std::cin>>couleur;
                    ///system("cls");
                    vc2=couleur;
                    std::cout<<"Dosage en bleu(0-255):" << std::endl;
                    std::cin>>couleur;
                    system("cls");
                    bc2=couleur;
                    std::cout<<std::endl;
                    std::cout<<"Quelle couleur pour les toits des chalets chinois ?" << std::endl;
                    std::cout<<"Dosage en rouge(0-255):" << std::endl;
                    std::cin>>couleur;
                    ///system("cls");
                    rc3=couleur;
                    std::cout<<"Dosage en vert(0-255):" << std::endl;
                    std::cin>>couleur;
                    ///system("cls");
                    vc3=couleur;
                    std::cout<<"Dosage en bleu(0-255):" << std::endl;
                    std::cin>>couleur;
                    system("cls");
                    bc3=couleur;
                    std::cout<<std::endl;
                }
                break;

                default:
                    break;
                }
            }
            break;
            case 3 :
            {
                choix3 = modif();
                switch(choix3)
                {
                case 1 :
                {
                    std::cout<<"Quelle valeur de graine pour les nuages et oiseaux ?"<<std::endl;
                    std::cin>>graine3;
                    system("cls");
                    std::cout<<std::endl;
                }
                break;
                case 2 :
                {
                    std::cout<<"Valeur de densite pour les oiseaux ?" <<std::endl;
                    std::cin>>densiteOiseaux;
                    system("cls");
                    std::cout<<std::endl;
                    std::cout<<"Valeur de densite pour les nuages ?" <<std::endl;
                    std::cin>>densiteNuages;
                    system("cls");
                    std::cout<<std::endl;
                }
                break;
                case 3 :
                {
                    std::cout<<"Quelle couleur pour les oiseaux ?" << std::endl;
                    std::cout<<"Dosage en rouge(0-255):" << std::endl;
                    std::cin>>couleur;
                    ///system("cls");
                    ro=couleur;
                    std::cout<<"Dosage en vert(0-255):" << std::endl;
                    std::cin>>couleur;
                    ///system("cls");
                    vo=couleur;
                    std::cout<<"Dosage en bleu(0-255):" << std::endl;
                    std::cin>>couleur;
                    system("cls");
                    bo=couleur;
                    std::cout<<std::endl;
                    std::cout<<"Quelle couleur pour les nuages ?" << std::endl;
                    std::cout<<"Dosage en rouge(0-255):" << std::endl;
                    std::cin>>couleur;
                    ///system("cls");
                    rn=couleur;
                    std::cout<<"Dosage en vert(0-255):" << std::endl;
                    std::cin>>couleur;
                    ///system("cls");
                    vn=couleur;
                    std::cout<<"Dosage en bleu(0-255):" << std::endl;
                    std::cin>>couleur;
                    system("cls");
                    bn=couleur;
                    std::cout<<std::endl;
                }
                break;
                default:
                    break;
                }
            }
            break;
            case 4 :
            {
                choix3 = modif();
                switch(choix3)
                {
                case 1 :
                {
                    std::cout<<"Quelle valeur de graine pour les montagnes ardentes du nord ?"<<std::endl;
                    std::cin>>graine4;
                    system("cls");
                    std::cout<<std::endl;
                }
                break;
                case 2 :
                {
                    std::cout<<"Valeur de densite de montagnes ?" <<std::endl;
                    std::cin>>densiteMontagnes;
                    system("cls");
                    std::cout<<std::endl;
                }
                break;
                case 3 :
                {
                    std::cout<<"Pour un degrader rouge : 1 " << std::endl;
                    std::cout<<"Pour un degrader vert : 2 " << std::endl;
                    std::cout<<"Pour un degrader bleu : 3 " << std::endl;
                    std::cout<<"Pour un degrader magenta : 4 " << std::endl;
                    std::cout<<"Pour un degrader cyan : 5" << std::endl;
                    std::cout<<"Pour un degrader jaune: 6 " << std::endl;
                    std::cout<<"Quelle couleur ?" << std::endl;

                    std::cin>>choixgradient;

                    system("cls");
                }
                break;

                default:
                    break;
                }
            }
            break;

            }
        }
        break;
        case 2 :
        {
            std::cout<<"Voila la plus belle scene du monde" << std::endl;

            Svgfile svgout;
            srand(time(NULL));
            double PosSoleil= util::alea(0,1200);
            Soleil sol = {PosSoleil, 100};
            Scene sceneg;
            Scene collines(graine2);
            sceneg.dessinerScene1(svgout, sol);
            creerMontagnes(svgout,graine4,densiteMontagnes,choixgradient);
            creerNuages(svgout,graine3,rn,vn,bn,densiteNuages);
            creerOiseaux(svgout,graine3,ro,vo,bo,densiteOiseaux);

            collines.dessinerScene22(svgout);
            creerChaletsColline2(svgout,graine2,rc2,vc2,bc2,densiteChalets2);

            collines.dessinerScene21(svgout);
            creerChaletsColline1(svgout,graine2,rc1,vc1,bc1,densiteChalets1);

            collines.dessinerScene23(svgout);
            creerChaletsColline3(svgout,graine2,rc3,vc3,bc3,densiteChalets3);

            sceneg.dessinerScene3(svgout);
            creerArbres(svgout,graine1,r1,v1,b1,r2,v2,b2,densiteArbres);

            ///svgout.addGrid();
        }
        break;
        case 3 :
            return 0;
        default:
            break;

        }
    }
    while(choix!=3);
    return 0;
}
