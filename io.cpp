
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
			else {
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
				if (j != 2) std::cout << " | ";

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

	// printBIG board




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
		//if (command.InitialMove) { // this will be the very first move. if the user is the one moving
			//std::cin >> column >> row;
		//}
		std::cin >> column >> row; // get the Loc of the min board

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