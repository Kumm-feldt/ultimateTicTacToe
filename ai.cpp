#include "ai.hpp"
#include <random>


namespace tictactoe {

bool AI::checkWin(Board cur, Label mC = Label::X) const {
	std::array<std::array<Cell, 3>, 3>grid = cur.copyCanvas();


	if (grid[0][0].label == Label::X and grid[1][1].label == mC and grid[2][2].label == mC) {
		return true;
	}
	if (grid[2][0].label == mC and grid[1][1].label == mC and grid[0][2].label == mC) {
		return true;
	}

	for (int i = 0; i < 3; i++) { // is this actually 3?
		if (grid[i][0].label == mC and grid[i][1].label == mC and grid[i][2].label == mC) {
			return true;
		}
		if (grid[0][i].label == mC and grid[1][i].label == mC and grid[2][i].label == mC) {
			return true;
		}
	}

	return false;
}

void AI::generateChilds(Node& current, Node& parent, Label moveCharacter) {
	if (checkWin(current.board, Label::X)) {
		current.evaluation = (this->moveCharacter == Label::X) ? 1 : -1;
		return;
	}
	if (checkWin(current.board, Label::O)) {
		current.evaluation = (this->moveCharacter == Label::O) ? 1 : -1;
		return;
	}

	bool isSpace = false;
	bool win = false;
	for (auto& row : current.board.copyCanvas()) {
		if (win) {
			break;
		}

		for (auto& cell : row) {
			if (cell.label == Label::Empty) {  // Check for empty cell
				Node child;
				count++;
				isSpace = true;

				// Make the move by setting the cell's label
				cell.label = moveCharacter == Label::X ? Label::X : Label::O;

				// Copy the current board state to the child node
				child.board = current.board;

				// Check if the move resulted in a win
				if (checkWin(current.board, moveCharacter)) {
					current.childs.push_back(child);
					win = true;
					break;
				}

				current.childs.push_back(child);

				// Undo the move (reset the cell)
				cell.label = Label::Empty;
			}
		}
	}

	if (!isSpace) {
		current.evaluation = 0;
		return;
	}

	moveCharacter = (moveCharacter == Label::X) ? Label::O : Label::X;

	for (Node& child : current.childs) {
		generateChilds(child, current, moveCharacter);
	}

}

int AI::minimax(Node& current, bool max, int alpha, int beta) {
	if (current.childs.size() == 0) {
		return current.evaluation;
	}

	if (max) {
		int maxEval = -10;
		for (Node& child : current.childs) {
			int eval = minimax(child, false, alpha, beta);
			maxEval = (eval > maxEval) ? eval : maxEval;
			alpha = (eval > alpha) ? eval : alpha;
			if (beta <= alpha) {
				break;
			}
		}
		current.evaluation = maxEval;
		return maxEval;

	}
	else {
		int minEval = 10;
		for (Node& child : current.childs) {
			int eval = minimax(child, true, alpha, beta);
			minEval = (eval < minEval) ? eval : minEval;
			beta = (eval < alpha) ? eval : beta;
			if (beta <= alpha) {
				break;
			}
		}
		current.evaluation = minEval;
		return minEval;
	}
}

void AI::createTree() {
	Board stateCopy = gameState;
	tree.board = stateCopy;
	generateChilds(tree, tree, moveCharacter);
}

AI::AI(Board gState, Label mChar) :gameState{ gState }, moveCharacter{ mChar } {
	createTree();
}

Location AI::Move() {
	int evaluation = minimax(tree, true);
	std::vector<Board> bestMoves;

	for (Node& child : tree.childs) {
		if (evaluation == child.evaluation) {
			bestMoves.push_back(child.board);
		}
	}

	if (bestMoves.empty()) {
		return { -1,-1 };
	}
	static std::random_device rd;
	static std::default_random_engine engine{ rd() };
	static std::uniform_int_distribution<> randomBestMove{ 0, int(bestMoves.size() - 1) };

	int number = randomBestMove(engine);

	Board bestMove = bestMoves[number];
	Location move;
	std::array<std::array<Cell, 3>, 3> gameStateGrid = gameState.copyCanvas();
	std::array<std::array<Cell, 3>, 3> bestMoveGrid = bestMove.copyCanvas();



	for (int i = 0; i < gameStateGrid.size(); i++) {
		for (int j = 0; j < gameStateGrid[0].size(); j++) {
			if (bestMoveGrid[i][j] != gameStateGrid[i][j]) {
				move = { i,j };
			}
		}
	}
	return move;
}
}