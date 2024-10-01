
#include <iostream>
#include "board.hpp";
#include "io.hpp";
#include "game.hpp";
#include "testAI.hpp";

using tictactoe::Game;
using tictactoe::Board;
using tictactoe::printCells;
using tictactoe::printBoard;
using tictactoe::printBoards;

using tictactoe::getCommand;
using tictactoe::Command;
using tictactoe::Label;
using tictactoe::BoardStatus;


using tictactoe::Location;
using tictactoe::getRandomMove;



using std::cout;
using std::cin;



int main()
{
	Location currBoard = { 1,1 };
	cout << "[row] [column]\n";
	char player;
	cout << "Choose player: (O,X) >";
	cin >> player;
	cout << "\n";
	Game game(player);
	Command cmd;
	Command cmdAi;
	bool initialMove = true;
	
	bool userQuit = false;
	Label gameStatus = Label::Empty;
	do {
		printBoards(game.boards);
		cout << "\n";

		Board boardCopy = game.returnBoardCopy();
		
		cmd = getCommand(boardCopy); // get very first move && first move.

		if (game.userQuit(cmd)) {
			userQuit = true;
		}
		else if (!game.invalidMove(cmd)) {
			if (initialMove) {
				std::cin >> currBoard.row >> currBoard.column;

				initialMove = false;
			}

			game.execute(cmd, currBoard);
			currBoard = { cmd.loc };
			// check 
			boardCopy = game.returnBoardCopy(cmd.loc);
			
			status(game.boardStatus(boardCopy));

			if (boardCopy.scoreStatus != BoardStatus::Won && boardCopy.status != BoardStatus::Covered) {
				Location aiMove = getRandomMove(game.boards[cmd.loc.row][cmd.loc.column].copyCanvas());
				cmdAi = getCommandAi(boardCopy, aiMove);
				game.executeAi(cmdAi, currBoard);
				currBoard = aiMove;

			}
			

		}

		
	} while (!game.gameOver() && !userQuit && game.returnBoardCopy().status != BoardStatus::Covered);
}
