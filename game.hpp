#pragma once

#include "board.hpp"
#include "io.hpp"


namespace tictactoe {


	class Game {
		Board board;

	public:
		std::array<std::array<Board, 3>, 3> boards;

		Game(char player);
		char user;
		char machine;
		bool gameOver();
		void execute(Command cmd, Location loc);
		void executeAi(Command cmd, Location loc);
		Label boardStatus(Board board);
		bool userQuit(Command cmd);
		
		Board returnBoardCopy();

		Board returnBoardCopy(Location loc);

		bool coveredBoard(Board board);
		bool invalidMove(Command cmd);
		bool isBoardCovered(Board board);
	};

}