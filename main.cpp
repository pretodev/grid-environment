
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

int correctIndex(int index, int size)
{
    if (index >= 0 && index < size)
        return index;

    char resp;
    std::cout << "Do you want to transport? (Y-yes|N-no) ";
    std::cin >> resp;
    if (resp == 'y' || resp == 'Y')
        index = index < 0 ? size - 1 : 0;
    return index;
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

        // show grid
        std::cout << "Grid: " << std::endl;
        grid.show();

        // read option
        std::cout << "1-North, 2-South, 3-East, 4-West, 5-Show neighbors:";
        std::cin >> direction;
        std::cin.ignore();

        switch (direction) {
            case 1: { // move to top
                int newRow = correctIndex(pointer.getRow() - 1, grid.dimension());
                if (grid.isValidIndex(newRow)) {
                    pointer.setRow(newRow);
                }
                break;
            }
            case 2: { // move to bottom
                int newRow = correctIndex(pointer.getRow() + 1, grid.dimension());
                if (grid.isValidIndex(newRow)) {
                    pointer.setRow(newRow);
                }
                break;
            }
            case 3: { // move to right
                int newCol = correctIndex(pointer.getCol() + 1, grid.dimension());
                if (grid.isValidIndex(newCol)) {
                    pointer.setCol(newCol);
                }
                break;
            }
            case 4: { // move to left
                int newCol = correctIndex(pointer.getCol() - 1, grid.dimension());
                if (grid.isValidIndex(newCol)) {
                    pointer.setCol(newCol);
                }
                break;
            }
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