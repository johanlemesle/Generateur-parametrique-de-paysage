#include "svgfile.h"
#include <iostream>
#include <sstream>

const std::string svgHeader =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
    "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" ";

const std::string svgEnding = "\n\n</svg>\n";

/// Effets "Boule en relief", voir données à la fin de ce fichier
extern const std::string svgBallGradients;

std::set<std::string> Svgfile::s_openfiles;

bool Svgfile::s_verbose = true;

Svgfile::Svgfile(std::string _filename, int _width, int _height) :
    m_filename{_filename}, m_width{_width}, m_height{_height}
{

    if (s_verbose)
        std::cout << "Opening SVG output file : "
                  << m_filename << std::endl;

    if ( s_openfiles.count(m_filename) )
        throw std::runtime_error( "File " + m_filename + " already open !" );

    m_ostrm.open(m_filename);
    s_openfiles.insert(m_filename);

    if (!m_ostrm)
    {
        std::cout << "Problem opening " << m_filename << std::endl;
        throw std::runtime_error("Could not open file " + m_filename );
    }

    if (s_verbose)
        std::cout << "OK" << std::endl;

    // Writing the header into the SVG file
    m_ostrm << svgHeader;
    m_ostrm << "width=\"" << m_width << "\" height=\"" << m_height << "\">\n\n";
}

Svgfile::~Svgfile()
{
    // Writing the ending into the SVG file
    m_ostrm << svgEnding;

    // Removing this file from the list of open files
    s_openfiles.erase(m_filename);

    // No need to explicitly close the ofstream object (automatic upon destruction)
}

// Helper templated function
template<typename T>
std::string attrib(std::string name, T val)
{
    std::ostringstream oss;
    oss << name << "=\"" << val << "\" ";
    return oss.str();
}

void Svgfile::addDisk(double x, double y, double r, std::string color)
{
    m_ostrm << "<circle "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("r",  r)
            << attrib("fill", color )
            << "/>\n";
}

void Svgfile::addEllipse(double x, double y, double rx, double ry,  std::string color)
{
    m_ostrm << "<ellipse "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("rx", rx)
            << attrib("ry", ry)
            << attrib("stroke", "clay")
            << attrib("stroke-width", "1")
            << attrib("fill", color )
            << "/>\n";

}

void Svgfile::addEllipse(double x, double y, double rx, double ry,  std::string color, std::string stroke)
{
    m_ostrm << "<ellipse "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("rx", rx)
            << attrib("ry", ry)
            << attrib("stroke", stroke)
            << attrib("stroke-width", "0.3")
            << attrib("fill", color )
            << "/>\n";

}

void Svgfile::addRectangle(double x, double y, double w, double h, std::string color)
{
    m_ostrm <<"<rect "
            << attrib("x", x)
            << attrib("y", y)
            << attrib("width", w)
            << attrib("height", h)
            << attrib("fill", color )
            << "/>\n";
}

void Svgfile::addCircle(double x, double y, double r, double ep, std::string color)
{
    m_ostrm << "<circle "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("r",  r)
            << attrib("fill", "none")
            << attrib("stroke", color )
            << attrib("stroke-width", ep )
            << "/>\n";
}

/// <polygon points="200,10 250,190 160,210" style="fill:lime;stroke:purple;stroke-width:1" />
/*void Svgfile::addTriangle(double x1, double y1, double x2, double y2,
                          double x3, double y3, std::string colorFill,
                          double thickness, std::string colorStroke)
{

    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3
            << "\" style=\"fill:" << colorFill
            << ";stroke:" << "brown"
            << ";stroke-width:" << "1"
            << "\" />\n";
}*/


void Svgfile::addTriangle(double x1, double y1, double x2, double y2,
                          double x3, double y3, std::string colorFill, std::string colorStroke)
{
    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3
            << "\" style=\"fill:" << colorFill
            << ";stroke:" << colorStroke
            << ";stroke-width:" << "0.3"
            << "\" />\n";
}

void Svgfile::addTriangle(double x1, double y1, double x2, double y2,
                          double x3, double y3, std::string colorFill)
{
    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3
            << "\" style=\"fill:" << colorFill
            << ";stroke:" << "transparent"
            << ";stroke-width:" << "0"
            << "\" />\n";
}

void Svgfile::addLine(double x1, double y1, double x2, double y2, std::string color)
{
    m_ostrm << "<line "
            << attrib("x1", x1)
            << attrib("y1", y1)
            << attrib("x2", x2)
            << attrib("y2", y2)
            << attrib("stroke", color)
            << "/>\n";
}

void Svgfile::addCross(double x, double y, double span, std::string color)
{
    addLine(x-span, y-span, x+span, y+span, color);
    addLine(x-span, y+span, x+span, y-span, color);
}

void Svgfile::addText(double x, double y, std::string text, std::string color)
{
    /// <text x="180" y="60">Un texte</text>
    m_ostrm << "<text "
            << attrib("x", x)
            << attrib("y", y)
            << attrib("fill", color)
            << ">" << text << "</text>\n";
}

void Svgfile::addText(double x, double y, double val, std::string color)
{
    std::ostringstream oss;
    oss << val;
    addText(x, y, oss.str(), color);
}

void Svgfile::addGrid(double span, bool numbering, std::string color)
{
    double y=0;
    while (y<=m_height)
    {
        addLine(0, y, m_width, y, color);
        if (numbering)
            addText(5, y-5, y, color);
        y+=span;
    }

    double x=0;
    while (x<=m_width)
    {
        addLine(x, 0, x, m_height, color);
        if (numbering)
            addText(x+5, 15, x, color);
        x+=span;
    }
}

void Svgfile::degrade()
{
    m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad1")
           << attrib ("x1","0%")
           << attrib ("y1","15%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(58, 137, 25);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";

        m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad2")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(164, 179,186);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";

        m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad3")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(92, 105,113);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
///rouge
         m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad4")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(225,0,0);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
///rouge sombre
        m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad5")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(217,1,21);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
///vert
         m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad6")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(0,255,0);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
///vert sombre
        m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad7")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(20,148,20);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
///bleu
        m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad8")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(0,0,255);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
///bleu sombre
        m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad9")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(16,52,166);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
///magenta
        m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad10")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(255,0,255);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
///magenta sombre
        m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad11")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(249,66,158);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
///cyan
        m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad12")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(0,255,255);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
///cyan ombre
        m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad13")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(10,186,181);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
///jaune
        m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad14")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(255,255,0);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";

 ///jaune ombre
         m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","grad15")
           << attrib ("x1","0%")
           << attrib ("y1","25%")
           << attrib ("x2","0%")
           << attrib ("y2","0%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(252,220,18);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";



        m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id","Plan3")
           << attrib ("x1","0%")
           << attrib ("y1","15%")
           << attrib ("x2","0%")
           << attrib ("y2","5%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("style","stop-color:rgb(0, 100, 0);stop-opacity:1 " ) << "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("style","stop-color:rgb(255,255,255);stop-opacity:1 " ) << "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
}

std::string Svgfile::makeRGB(int r, int g, int b)
{
    std::ostringstream oss;
    oss << "rgb(" << r << "," << g << "," << b << ")";
    return oss.str();
}
