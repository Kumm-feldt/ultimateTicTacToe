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
	};

	int  lineCount(Cell cell, Board board, Label l) {
		int x = 0;
		if (cell.status == Status::Covered) { // per row
			if (cell.label == l) {
				x++;
			}
		} 
		return x;
	}

	int  crossCount(Label l, Board board) {
		int label=0;
		int row = 0;
		int col = 0;
		for (int i = 0; i < 3; i++)
		{
			Cell cell = board.getCell(i, col);

			if (cell.status == Status::Covered) { // per row
				if (cell.label == l) {
					label++;
				}
			}
			col++;
		}
		if (label == 3) { 
			return label; 
		}
		else { 
			label = 0; 
		};
			
		for (int i = 2; i >=0; i--)
		{
			Cell cell = board.getCell(row, i);

			if (cell.status == Status::Covered) { // per row
				if (cell.label == l) {
					label++;
				}
			}
			row++;
		}
		
		return label;
	}


	Label Game::boardStatus(Board board) {

		if (isBoardCovered(board)) {
			board.status = BoardStatus::Covered;
		}

		if (crossCount(Label::X, board)>=3) {
			board.scoreStatus = BoardStatus::Won;
			return Label::X;
		}
		else if (crossCount(Label::O, board) >= 3) {
			board.scoreStatus = BoardStatus::Won;

			return Label::O;

		}
		else {
			for (int row = 0; row < 3; row++) {
				int x_row = 0;
				int o_row = 0;
				int x_col = 0;
				int o_col = 0;
		
				for (int column = 0; column < 3; column++) {
					Cell currentCell = board.getCell(row, column);
					x_row += lineCount(board.getCell(row, column), board, Label::X);
					o_row += lineCount(board.getCell(row, column), board, Label::O);
					x_col += lineCount(board.getCell(column, row), board, Label::X);
					o_col += lineCount(board.getCell(column, row), board, Label::O);
					if (o_row == 3 || o_col == 3) { 
						board.scoreStatus = BoardStatus::Won;
						return Label::O; 
					}
					else if (x_row == 3 || x_col==3) { 
						board.scoreStatus = BoardStatus::Won;
						return Label::X; }
				}
			}
		}

		return Label::Empty;
	}


	bool Game::coveredBoard(Board board) {
		bool boardCovered = false;
		if (board.status == BoardStatus::Covered) {
			boardCovered = true;
		}
		return boardCovered;
	}
	bool Game::isBoardCovered(Board board) {
		bool boardCovered = true;
		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				if (board.getCell(row, column).status == Status::Uncovered) {
					boardCovered = false;
				}
			}
		}
		return boardCovered;
	}
	
	Board Game::returnBoardCopy() {
		Board boardCopy;
		boardCopy = board;
		return boardCopy;
	}

	Board Game::returnBoardCopy(Location loc) {
		Board boardCopy;
		boardCopy = boards[loc.row][loc.column];
		return boardCopy;
	}


	void Game::execute(Command cmd, Location loc) {
		char player = this->user;
		int row = cmd.loc.row;
		int column = cmd.loc.column;

		if (cmd.op == Operation::Play) {
				if (player == 'X') {
					boards[loc.row][loc.column].setLabel(row, column, Label::X);
				}
				else {
					boards[loc.row][loc.column].setLabel(row, column, Label::O);
				}
				boards[loc.row][loc.column].setStatus(row, column, Status::Covered);

		}
		
	}

	void Game::executeAi(Command cmd, Location loc) {
		char player = this->user;
		int row = cmd.loc.row;
		int column = cmd.loc.column;

		if (cmd.op == Operation::Play) {
			if (player == 'X') {
				boards[loc.row][loc.column].setLabel(row, column, Label::O);
			}
			else {
				boards[loc.row][loc.column].setLabel(row, column, Label::X);
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