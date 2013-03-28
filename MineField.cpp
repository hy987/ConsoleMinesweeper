#include "MineField.h"
#include <iostream>
#include <iomanip>
using namespace std;

MineField::MineField(int _height, int _width, int _mines): actual_field(_height, _width), visual_field(_height, _width)
{
	height = _height;
	width = _width;
	mines = _mines;

	set_mines();
	calculate_cells();
}

void MineField::set_cell_actual_value(int x, int y, int value)
{
	actual_field.set_cell_value(x, y, value);
}

void MineField::set_cell_visual_value(int x, int y, char symbol)
{
	visual_field.set_cell_value(x, y, symbol);
}

void MineField::set_mines()
{
	int random_x_coordinate;
	int random_y_coordinate;
	int mine_counter = 0;
	
	while(mine_counter < mines)
	{
		random_x_coordinate = rand()%height;
		random_y_coordinate = rand()%width;

		if (!actual_field.get_cell_value(random_x_coordinate, random_y_coordinate))
		{
			actual_field.set_cell_value(random_x_coordinate, random_y_coordinate, -1);
			mine_counter++;
		}
	}	
}

void MineField::calculate_cells()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (actual_field.get_cell_value(i, j) != -1)
				actual_field.set_cell_value(i, j, check_surrounding_cells(i, j));
}

int MineField::check_surrounding_cells(int x, int y) const
{
	bool first_cell = (x-1 >= 0) && (x-1 < height) && (actual_field.get_cell_value(x-1, y) == -1);

	bool second_cell = (y-1 >= 0) && (y-1 < width) && (actual_field.get_cell_value(x, y-1) == -1);

	bool third_cell = (x+1 >= 0) && (x+1 < height) && (actual_field.get_cell_value(x+1, y) == -1);

	bool fourth_cell = (y+1 >= 0) && (y+1 < width) && (actual_field.get_cell_value(x, y+1) == -1);

	bool fifth_cell = (x-1 >= 0) && (x-1 < height) && (y+1 >= 0) && (y+1 < width) && 
		(actual_field.get_cell_value(x-1, y+1) == -1);

	bool sixth_cell = (x+1 >= 0) && (x+1 < height) && (y+1 >= 0) && (y+1 < width) &&
		(actual_field.get_cell_value(x+1, y+1) == -1);

	bool seventh_cell = (x-1 >= 0) && (x-1 < height) && (y-1 >= 0) && (y-1 < width) &&
		(actual_field.get_cell_value(x-1, y-1) == -1);

	bool eigth_cell = (x+1 >= 0) && (x+1 < height) && (y-1 >= 0) && (y-1 < width) &&
		(actual_field.get_cell_value(x+1, y-1) == -1);

	return first_cell + second_cell + third_cell + fourth_cell + fifth_cell + sixth_cell + seventh_cell + eigth_cell;
}

void MineField::print() const
{
	visual_field.print_matrix();
}