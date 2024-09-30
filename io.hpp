#pragma once
#include "board.hpp"
#include <vector>
#include <string>


namespace tictactoe {
	enum class GameResult {
		Win,
		Lost
	};

	enum class Operation {
		Play,
		Quit, 
		Invalid
	};


	struct Command {
		Operation op;
		Location loc;
		bool InitialMove = true;
	};

	bool inBounds(int row, int column);

	void printBoard(Board board);
	void printCells(Board board, int row, int column);
	Command getCommand(Board board);
	Command getCommandAi(Board board, Location loc);
}