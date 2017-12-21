//
// Created by santor on 20/12/17.
//

#ifndef GRID_ENVIROMENT_AGENT_H
#define GRID_ENVIROMENT_AGENT_H


class Agent
{
public:
    explicit Agent(long index);

    enum status
    {
        LIVE,
        DEAD
    };

    void update();

    status state();

private:
    long m_position;
    status m_state; //TODO: use ENUM
};


#endif //GRID_ENVIROMENT_AGENT_H
