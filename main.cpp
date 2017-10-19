
#include <unistd.h>
#include <term.h>
#include <iostream>
#include <limits>

#include "grid.h"
#include "pointer.h"

void clearScreen()
{
    if (!cur_term) {
        int result;
        setupterm(NULL, STDOUT_FILENO, &result);
        if (result <= 0) return;
    }

    putp(tigetstr("clear"));
}

bool transport(bool condition)
{
    if (condition) {
        char resp;
        std::cout << "Do you want to transport row? (Y-yes|N-no) ";
        std::cin >> resp;
        if (resp == 'y' || resp == 'Y') {
            return true;
        }
    }
    return false;
}

int main()
{
    int direction = 0;
    Grid grid(10);
    Pointer pointer;

    int index = 0;
    while (index < 500) {
        clearScreen();
        grid.setPosition(pointer.getRow(), pointer.getCol());

        std::cout << "Grid: " << std::endl;
        grid.show();

        std::cout << "1-North, 2-South, 3-East, 4-West, 5-Show neighbors:";
        std::cin >> direction;
        std::cin.ignore();

        switch (direction) {
            case 1:
                if (transport(pointer.getRow() == 0))
                    pointer.setRow(grid.dimension() - 1);
                else
                    pointer.setRow(pointer.getRow() - 1);
                break;
            case 2:
                if (transport(pointer.getRow() == (grid.dimension() - 1)))
                    pointer.setRow(0);
                else
                    pointer.setRow(pointer.getRow() + 1);
                break;
            case 3:
                if (transport(pointer.getCol() == (grid.dimension() - 1)))
                    pointer.setCol(0);
                else
                    pointer.setCol(pointer.getCol() + 1);
                break;
            case 4:
                if (transport(pointer.getCol() == 0))
                    pointer.setCol(grid.dimension() - 1);
                else
                    pointer.setCol(pointer.getCol() - 1);
                break;
            case 5:
                grid.positionNeighbors();
                std::cout << "Press Enter to Continue";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            default:
                std::cout << "Invalid input" << std::endl;
        }
        index++;
    }

    return 0;
}