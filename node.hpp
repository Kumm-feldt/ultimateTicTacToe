#pragma once
#include <vector>
#include "board.hpp"

namespace tictactoe {

	
	struct Node {
		Board board;
		std::vector<Node> childs;
		int evaluation;
	};
}

