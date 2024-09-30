#pragma once
#include <array>

namespace tictactoe {

	enum class Status {
		Covered,
		Uncovered
	};

	enum class BoardStatus {
		Covered, 
		Won, 
		Uncovered,
		Tie
	};

	struct Location {
		int row;
		int column;
	};

	enum class Label {
		X,
		O,
		Empty
	};

	struct Cell {
		Label label;
		Status status;
	};


	class Board {
		std::array<std::array<Cell, 3>, 3> canvas;
	public:
		std::array<std::array<Cell, 3>, 3>copyCanvas() {
			return canvas;
		};

		BoardStatus status;
		void reset();
		Cell getCell(int row, int column);
		Board();
		
		bool inBounds(int row, int column);
		void setStatus(int row, int column, Status st);
		bool isCovered(int row, int column);
		void setLabel(int row, int column, Label label);
	};

}
