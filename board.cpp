#include <array>
#include "board.hpp"


namespace tictactoe {

	Board::Board() { //need to reset Board
		reset();
	};


	Cell Board::getCell(int row, int column) { // might need to get Cell
		if (inBounds(row, column))
		{
			return canvas[row][column];
		}

	};
	

	void Board::setStatus(int row, int column, Status status) { // covered or uncovered
		if (inBounds(row, column))
		{
			canvas[row][column].status = status;

		}
	};


	bool Board::inBounds(int row, int column) { 
		bool inBounds = false;
		if (row >= 0 && column >= 0 && row < 9 && column < 9) {
			inBounds = true;
		}
		return inBounds;

	};

	bool Board::isCovered(int row, int column) {
		bool isCovered = false;
		if (canvas[row][column].status == Status::Covered) {
			isCovered = true;
		}
		return isCovered;
	};


	void Board::reset() {
		for (auto& row : canvas) {
			for (auto& cell : row) {
				cell.status = Status::Uncovered;
				cell.label = Label::Empty;
			}
		}
	}

	void Board::setLabel(int row, int column, Label label) {

		if (inBounds(row, column)) {
			canvas[row][column].label = label;
			canvas[row][column].status = Status::Covered;
		}
		
	}
	

	
}











