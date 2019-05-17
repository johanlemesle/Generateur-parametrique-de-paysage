#include "forme.h"

Forme::Forme(double x,double y, uint8_t rouge, uint8_t vert, uint8_t bleu) : m_position{x,y},m_couleur{rouge,vert,bleu}
{
}

double Forme::getPosition()
{
    return m_position;
}
