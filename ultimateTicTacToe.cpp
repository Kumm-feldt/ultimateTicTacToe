
#include <iostream>
#include "board.hpp";
#include "io.hpp";
#include "game.hpp";
#include "testAI.cpp";

using tictactoe::Game;
using tictactoe::Board;
using tictactoe::printCells;
using tictactoe::printBoard;
using tictactoe::getCommand;
using tictactoe::Command;
using tictactoe::Location;
using tictactoe::getRandomMove;



using std::cout;
using std::cin;



int main()
{
	char player;
	cout << "Choose player: (O,X) >";
	cin >> player;
	Game game(player);
	Command cmd;
	Command cmdAi;
	
	bool userQuit = false;

	do {
		Location aiMove = getRandomMove(game.returnBoardCopy().copyCanvas());

		printBoard(game.returnBoardCopy()); // print initial board
		cmd = getCommand(game.returnBoardCopy());
		if (game.userQuit(cmd)) {
			userQuit = true;
		}
		else if (!game.invalidMove(cmd)) {
			cmd.InitialMove = false;

			game.execute(cmd);
			// check 

			cmdAi = getCommandAi(game.returnBoardCopy(), aiMove);
			game.executeAi(cmd);

		}

		
	} while (!game.gameOver() && !userQuit);
}
