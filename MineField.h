#ifndef MINEFIELD_H
#define MINEFIELD_H

#include "Matrix.h"

class MineField
{
public:
	MineField(int, int, int);

	void set_cell_actual_value(int, int, int);
	void set_cell_visual_value(int, int, char);

	int get_height() const
	{
		return height;
	}

	int get_width() const
	{
		return width;
	}

	int get_cell_actual_value(int x, int y) const
	{
		return actual_field.get_cell_value(x, y);
	}

	char get_cell_visual_value(int x, int y) const
	{
		return visual_field.get_cell_value(x, y);
	}

	void print() const;

private:
	int height, width, mines;
	
	Matrix<int> actual_field;
	Matrix<char> visual_field;

	void set_mines();
	void calculate_cells();
	int check_surrounding_cells(int, int) const;
};

#endif