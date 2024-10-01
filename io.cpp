
#include <vector>
#include<cctype>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include "io.hpp"
#include "board.hpp"

using std::vector;
namespace tictactoe {

	// cout

	void printRow(const Board& board, int row) {
		Graphics graphics;
		for (int col = 0; col < 3; ++col) {
			printCells(board, row, col);
			
			if (col < 2) {
				std::cout <<" "<< graphics.line<<" ";
			}
		}
	}

	void printBoardRow(const std::array<std::array<Board, 3>, 3>& boards, int boardRow, int cellRow) {
		Graphics graphics;
		for (int boardCol = 0; boardCol < 3; ++boardCol) {
			printRow(boards[boardRow][boardCol], cellRow);
			if (boardCol < 2) {
				std::cout << " "<<graphics.fullBlock<<" ";
			}
		}
		std::cout << std::endl;
	}

	void printBoards(const std::array<std::array<Board, 3>, 3>& boards) {
		Graphics graphics;
		for (int boardRow = 0; boardRow < 3; ++boardRow) {
			for (int cellRow = 0; cellRow < 3; ++cellRow) {
				printBoardRow(boards, boardRow, cellRow);
			}
			if (boardRow < 2) {
				for (size_t i = 0; i < 3; i++)
				{
					if (i == 1) {
						std::cout << graphics.horizontal;

					}
					for (size_t j = 0; j < 10; j++)
					{
						
						std::cout << graphics.horizontal;
					}
					if (i < 2) {
						std::cout << graphics.fullBlock;

					}
				}
				std::cout << "\n";
			}
		}
	}



	void status(Label gameStatus) {
		if (gameStatus == Label::O) {
			std::cout << "O won\n";
			
		}
		else if (gameStatus == Label::X) {
			std::cout << "X won \n";
		}
	}

	bool incorrectMark(Board board, int row, int column) {
		Cell cell = board.getCell(row, column);
		return cell.status == Status::Covered;
	}

	
	void printCells(Board board, int row, int column) {
		Cell cell = board.getCell(row, column);

		if (cell.status == Status::Covered) {
			if (cell.label == Label::X) {
				std::cout << "X";
			}
			else if(cell.label == Label::O){
				std::cout << "O";

			}
		}
		else if (cell.status == Status::Uncovered) {
			std::cout << " ";
		}
	}


	// printMiniBoard
	void printBoard(Board board) {

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				printCells(board, i, j);
				if (j != 2) {
					std::cout << " | ";

				}
				

			}
			std::cout << std::endl;
			if (i < 2){
				for (int l = 0; l < 3; l++) {
					 std::cout << "---";
				}
			}
			std::cout <<"\n";


		}
	}




	void printGameResult(int score, Operation op) {
		if (score == 32) {
			std::cout << "Congratulations!  You win!\nYour score was " << score << '.';
		}
		else if (op == Operation::Quit) {
			std::cout << "User quit" << '.' << std::endl;
		}
		else {
			std::cout << "Boom!  You died." << std::endl;
			std::cout << "Your score was " << score << '.' << std::endl;
		}
	}

	bool inBounds(int row, int column) {
		bool inBounds = false;
		if (row >= 0 && column >= 0 && row < 3 && column < 3) {
			inBounds = true;
		}
		return inBounds;

	};

	Command getCommand(Board board) {
		Command command;
		Operation op = Operation::Play;
		int column;
		int row;
	
		std::cin >> row >> column; // get the Loc of the min board

		if (column == -1 && row == -1) {
			op = Operation::Quit;

		}else if(inBounds(row, column) && !board.isCovered(row, column)){

			op = Operation::Play;

		}else {
			op = Operation::Invalid;
			std::cout << "Invalid board specification. Try again." << std::endl;
		}
		command.op = op;
		command.loc = {row, column};
		return command;
	};

	Command getCommandAi(Board board, Location loc) {
		Command command;
		Operation op = Operation::Play;
	
		if (loc.column == -1 && loc.row == -1) {
			op = Operation::Quit;

		}
		else if (inBounds(loc.row, loc.column) && !board.isCovered(loc.row, loc.column)) {

			op = Operation::Play;

		}
		else {
			op = Operation::Invalid;
			std::cout << "Invalid board specification. Try again." << std::endl;
		}
		command.op = op;
		command.loc = loc;
		return command;
	};


};