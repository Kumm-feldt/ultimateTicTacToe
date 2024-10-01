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
	struct Graphics {
		 char line = 179;
		 char fullBlock = 186;
		 char horizontal = 196;


	};


	struct Command {
		Operation op;
		Location loc;
		//bool InitialMove = true;
	};

	bool inBounds(int row, int column);
	//Graphics graphics;
	void printBoard(Board board);
	void printBoards(const std::array<std::array<Board, 3>, 3>& boards);
	void printCells(Board board, int row, int column);
	Command getCommand(Board board);
	Command getCommandAi(Board board, Location loc);
	void status(Label label);
}