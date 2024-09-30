#pragma once

#include "board.hpp"
#include "io.hpp"

namespace tictactoe {

	class Game {
		Board board;

	public:
		Game(char player);
		char user;
		char machine;
		bool gameOver();
		void execute(Command cmd);
		void executeAi(Command cmd);
		bool boardStatus(Board board);
		bool userQuit(Command cmd);
		Board returnBoardCopy();
		bool coveredBoard(Board board);
		bool invalidMove(Command cmd);
	};

}