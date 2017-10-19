//
// Created by santor on 19/09/17.
//

#ifndef GRID_ENVIROMENT_GRID_H
#define GRID_ENVIROMENT_GRID_H


class Grid
{
public:
    explicit Grid(int dimension);
    ~Grid();

    void setPosition(int line, int column);

    int row() const;
    int column() const;
    int dimension() const;

    void show();

    void positionNeighbors();

private:
    int m_dimension;
    int* m_gridElements;
    int m_position;
};


#endif //GRID_ENVIROMENT_GRID_H
