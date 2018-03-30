//
// Created by santor on 20/12/17.
//

#include <iostream>
#include <thread>

#include "environment.h"
#include "agent.h"

int main()
{
    unsigned int steps = 500;
    unsigned int dimension = 35;
    unsigned int stepTime = 100;

    // cria o ambiente
    EnvInit(dimension);

    // adiciona os agentes
    for (int i = 0; i < Env()->countElements(); ++i) {
        Env()->addAgent(i);
    }

    // executa passos
    for (int j = 0; j < steps; ++j) {
        // atualiza os agentes
        std::cout << "\033c"; //clear screen
        std::cout << "Step: " << (j + 1) << std::endl;
        for (const auto &agent : Env()->agents()) {
            agent->update();
        }
        Env()->show();
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(stepTime));
    }

    return 0;
}