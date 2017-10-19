//
// Created by santor on 19/10/17.
//

#ifndef GRID_ENVIROMENT_POINTER_H
#define GRID_ENVIROMENT_POINTER_H


class Pointer
{
public:
    Pointer();

    int getCol() const;
    void setCol(int posX);
    int getRow() const;
    void setRow(int posY);
private:
    int m_posX, m_posY;
};


#endif //GRID_ENVIROMENT_POINTER_H
