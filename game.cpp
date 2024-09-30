#include "board.hpp"
#include "game.hpp"

namespace tictactoe {

	bool Game::gameOver() {
		bool gameIsOver = false;
		// need to find a way to check all boards -> for loop of 9
		if (coveredBoard(board)) {
			gameIsOver = true;
		}

		return gameIsOver;
	}
	bool boardStatus(Board board) {
	
	};


	bool Game::coveredBoard(Board board) {
		bool boardCovered = false;
		if (board.status == BoardStatus::Covered) {
			boardCovered = true;
		}
		return boardCovered;
	}
	Board Game::returnBoardCopy() {
		Board boardCopy;
		boardCopy = board;
		return boardCopy;
	}

	void Game::execute(Command cmd) {
		char player = this->user;
		int row = cmd.loc.row;
		int column = cmd.loc.column;

		if (cmd.op == Operation::Play) {
				board.setStatus(row, column, Status::Covered);
				if (player == 'X') {
					board.setLabel(row, column, Label::X);
				}
				else {
					board.setLabel(row, column, Label::O);
				}
		}
		
	}

	void Game::executeAi(Command cmd) {
		char player = this->user;
		int row = cmd.loc.row;
		int column = cmd.loc.column;

		if (cmd.op == Operation::Play) {
			board.setStatus(row, column, Status::Covered);
			if (player == 'X') {
				board.setLabel(row, column, Label::O);
			}
			else {
				board.setLabel(row, column, Label::X);
			}
		}

	}


	bool Game::userQuit(Command cmd) {
		bool userQuit = false;
		if (cmd.op == Operation::Quit) {
			userQuit = true;
		}
		return userQuit;
	}
	bool Game::invalidMove(Command cmd) {
		bool invalid = false;
		if (cmd.op == Operation::Invalid) {
			invalid = true;
		}
		return invalid;
	}

	Game::Game(char user) {
		if (user == 'X') {
			this->user = user;
			this->machine = 'O';
		}
		else {
			this->user = 'O';
			this->machine = 'X';
		}
	}
}