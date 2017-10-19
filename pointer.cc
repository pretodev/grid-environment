//
// Created by santor on 19/10/17.
//

#include "pointer.h"

Pointer::Pointer()
        : m_posX(0), m_posY(0)
{

}

int Pointer::getCol() const
{
    return m_posX;
}

void Pointer::setCol(int posX)
{
    m_posX = posX;
}

int Pointer::getRow() const
{
    return m_posY;
}

void Pointer::setRow(int posY)
{
    m_posY = posY;
}
