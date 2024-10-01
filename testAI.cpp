
#include "testAi.hpp";

namespace tictactoe {

    Location getRandomMove(const std::array<std::array<Cell, 3>, 3>& canvas) {
        // Seed the random generator
        std::srand(static_cast<unsigned int>(std::time(0)));

        // Store all available moves (uncovered and empty cells)
        std::vector<Location> availableMoves;

        for (int row = 0; row < 3; ++row) {
            for (int column = 0; column < 3; ++column) {
                if (canvas[row][column].label == Label::Empty &&
                    canvas[row][column].status == Status::Uncovered) {
                    availableMoves.push_back({ row, column });
                }
            }
        }

        // If there are no available moves, return a dummy move (-1, -1)
        if (availableMoves.empty()) {
            return { -1, -1 };
        }

        // Randomly select a move from available moves
        int randomIndex = std::rand() % availableMoves.size();
        return availableMoves[randomIndex];
    }

}  // namespace tictactoe
