//
// Created by santor on 19/09/17.
//

#include "grid.h"

#include <iostream>

Grid::Grid(int dimension)
{
    m_dimension = dimension;
    m_position = 0;

    int size = dimension * dimension;
    m_gridElements = new int[size];
    //TODO: check if can create array with size
}

Grid::~Grid()
{
    delete m_gridElements;
}

void Grid::setPosition(int line, int column)
{
    //TODO: check if is a Valid position
    m_gridElements[m_position] = 0;
    m_position = (line * m_dimension) + column;
    m_gridElements[m_position] = 1;
}

int Grid::row() const
{
    return (m_position - column()) / m_dimension;
}

int Grid::column() const
{
    return m_position % m_dimension;
}

void Grid::show()
{
    for (int i = 0; i < m_dimension; ++i) {
        for (int j = 0; j < m_dimension; ++j) {
            int pos = j + (m_dimension * i);
            std::cout << m_gridElements[pos] << " ";
        }
        std::cout << std::endl;
    }
}

int Grid::dimension() const
{
    return m_dimension;
}

void Grid::positionNeighbors()
{
    int row = Grid::row() - 1;
    int col = Grid::column() - 1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "(" << (row + i) << ", " << (col + j) << ") ";
        }
    }
    std::cout << std::endl;
}


