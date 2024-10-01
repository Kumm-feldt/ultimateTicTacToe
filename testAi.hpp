#pragma once
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For seeding random generator
#include <vector>  // For storing available moves
#include "board.hpp";

namespace tictactoe {
    Location getRandomMove(const std::array<std::array<Cell, 3>, 3>& board);  // Declaration only
}