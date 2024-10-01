#pragma once
#include "node.hpp"
#include "board.hpp"

namespace tictactoe {

	class AI {
	public:
		AI(Board gStatel, Label mChar);
		Location play() {
			return Move();
		}
		int count = 0;
	private:
		const Label moveCharacter;
		 Board gameState;
		Location move;

		Node tree;

		int minimax(Node& tree, bool max, int alpha = -999, int beta = 999);
		void createTree();
		void generateChilds(Node& current, Node& parent, Label mC);
		bool checkWin(Board cur, Label mC) const;
		Location Move();
	};

}
