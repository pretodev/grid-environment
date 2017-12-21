//
// Created by santor on 19/09/17.
//

#include <iostream>
#include "environment.h"
#include "agent.h"
#include "defs.h"

Environment* Environment::s_instance = nullptr;

void Environment::initialize(long dimension)
{
    if (!s_instance)
        s_instance = new Environment(dimension);
}


Environment* Environment::get()
{
    if (!s_instance)
        throw std::invalid_argument("environment not initialized");
    return s_instance;
}

void Environment::destroy()
{
    delete s_instance;
}


// TODO: define if matriz is circular or not
Environment::Environment(long dimension)
{
    m_dimension = dimension;

    m_size = dimension * dimension;

    m_elements = new PCell[m_size]; // TODO: check if can create array with size
}

Environment::~Environment()
{
    delete m_elements;
}

long Environment::countElements() const
{
    return m_size;
}

void Environment::addAgent(long index)
{
    PAgent agent = std::make_shared<Agent>(index);
    this->m_agents.push_back(agent);

    PCell cell = std::make_shared<Cell>();
    cell->agent = agent;
    cell->index = index; // TODO: add agent in the first empty space, if index equals -1

    m_elements[index] = cell;
}

const std::vector<PAgent> &Environment::agents() const
{
    return m_agents;
}

void Environment::show()
{
    for (int i = 0; i < m_dimension; ++i) {
        for (int j = 0; j < m_dimension; ++j) {
            PAgent agent = m_elements[(i * m_dimension) + j]->agent;
            std::cout << ((agent->state() == Agent::LIVE) ? "·" : " ") << " ";
        }
        std::cout << std::endl;
    }
}

long Environment::dimension() const
{
    return m_dimension;
}

PCell* Environment::neighborsFrom(long index)
{
    auto neighbors = new PCell[8];

    long col = index % m_dimension;
    long row = (index - col) / m_dimension;

    int nindex = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i != 1 || j != 1) {
                long nrow = (correctPosition(row + i - 1));
                long ncol = correctPosition(col + j - 1);
                neighbors[nindex] = m_elements[(nrow * m_dimension) + ncol];
                ++nindex;
            }
        }
    }

    return neighbors;
}


long Environment::correctPosition(long position)
{
    if (position >= m_dimension)
        return 0;
    else if (position < 0)
        return (m_dimension - 1);
    return position;
}




