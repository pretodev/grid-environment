//
// Created by santor on 20/12/17.
//

#ifndef GRID_ENVIROMENT_TYPES_H
#define GRID_ENVIROMENT_TYPES_H

#include <memory>

class Agent;

typedef std::shared_ptr<Agent> PAgent;

typedef struct {
    long index;
    PAgent agent = nullptr;
} Cell;

typedef std::shared_ptr<Cell> PCell;



#endif //GRID_ENVIROMENT_TYPES_H
