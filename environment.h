//
// Created by santor on 19/09/17.
//

#ifndef GRID_ENVIROMENT_GRID_H
#define GRID_ENVIROMENT_GRID_H

#include <vector>

#include "defs.h"

/**
 * @brief Initialize the environment
 * @param dimension size of the environment
 */
#define EnvInit(dimension) (Environment::initialize(dimension))

/**
 * @brief Get environment, throw error if not initialized
 * @see EnvInit
 */
#define Env()   (Environment::get())

class Environment
{
public:

    ~Environment();

    static void initialize(long dimension);

    static void destroy();

    static Environment* get();

    long countElements() const;

    void addAgent(long index = -1);

    const std::vector<PAgent> &agents() const;

    void show();

    long dimension() const;

    PCell* neighborsFrom(long index);

private:

    static Environment* s_instance;

    long m_dimension;
    long m_size;

    PCell* m_elements;
    std::vector<PAgent> m_agents;

    explicit Environment(long dimension);

    long correctPosition(long position);
};


#endif //GRID_ENVIROMENT_GRID_H
