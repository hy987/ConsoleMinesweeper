#include "IntMatrix.h"
#include "CharMatrix.h"

#ifndef MINEFIELD_H
#define MINEFIELD_H

class MineField
{
public:
	//конструктори
	MineField();
	MineField(int, int, int);

	//мутатори
	void set_cell_actual_value(int, int, int);
	void set_cell_visual_value(int, int, char);
	void set_mines();
	void calculate_cells();
	void alter_minefield(int, int, int);

	
	

	//функции за достъп
	int check_surrounding_cells(int, int) const;

	int get_height() const
	{
		return height;
	}

	int get_width() const
	{
		return width;
	}

	IntMatrix get_actual_field()  const
	{
		return actual_field;
	}

	CharMatrix get_visual_field() const
	{
		return visual_field;
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
	//член данни
	int height, width, mines;
	IntMatrix actual_field;
	CharMatrix visual_field;
};

#endif