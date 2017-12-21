//
// Created by santor on 20/12/17.
//

#include <iostream>
#include "agent.h"
#include "environment.h"

Agent::Agent(long index)
        : m_state(LIVE),
          m_position(index) {}

void Agent::update()
{
    int contAgentsLives = 0;

    auto cells = Env()->neighborsFrom(m_position);
    for (int i = 0; i < 8; ++i) {
        PAgent agent = cells[i]->agent;
        if (agent && agent->state() == LIVE)
            ++contAgentsLives;
    }

    if (m_state == DEAD) {
        if (contAgentsLives == 3)
            m_state = LIVE;
    } else {
        if (contAgentsLives < 2 || contAgentsLives > 3)
            m_state = DEAD;
    }
}

Agent::status Agent::state()
{
    return m_state;
}




