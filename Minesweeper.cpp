#include "Minesweeper.h"
#include <iostream>
using namespace std;

Minesweeper::Minesweeper(): playing_field(MineField(0, 0, 0))
{
	state = UNINITIALIZED;
}

void Minesweeper::set_mode()
{
	menu();

	int number, _height, _width, _mines;
	do
	{
		if (!cin)
			flushing_cin();

		cout << "Enter a number(1-5): ";
		cin >> number;
	}
	while(!cin || number < 1 || number > 5);

	switch (number)
	{
	case 1:
		playing_field = MineField(9, 9, 10);
		state = INITIALIZED;
		break;
	
	case 2:
		playing_field = MineField(16, 16, 40);
		state = INITIALIZED;
		break;

	case 3:
		playing_field = MineField(16, 30, 99);
		state = INITIALIZED;
		break;

	case 4:
		cout << endl;
		do
		{
			flushing_cin();
			cout << "Board height: ";
			cin >> _height;
		}
		while (!cin);
	
		do
		{
			flushing_cin();
			cout << "Board width: ";
			cin >> _width;
		}
		while (!cin);

		do
		{
			if (!cin)
				flushing_cin();

			cout << "Number of mines(less than " << _width * _height <<"): ";
			cin >> _mines;
		}
		while (!cin || _mines > _width * _height);

		playing_field = MineField(_height, _width, _mines);
		state = INITIALIZED;
		break;

	case 5:
		state = EXIT;
		break;

	default:
		state = EXIT;
		cout << "ERROR!\n";
		break;
	}
}

void Minesweeper::make_a_step(int& x_coordinate, int& y_coordinate, int& command) const
{
	do
		{
			system("cls");
			
			playing_field.print();
			
			cout << endl;
			cout << "1  - Flag cell\n";
			cout << "2  - Open cell\n";
			cout << endl;
			cout << "Enter command: ";
			cin >> command;
			
			if (!cin)
				flushing_cin();
			else
			{
				cout << "\nEnter cell coordinates: ";
				cin >> x_coordinate >> y_coordinate;
				if (!cin)
					flushing_cin();
			}
			
		}
		while(!cin || x_coordinate < 0 || x_coordinate >= playing_field.get_height() || 
			y_coordinate < 0 || y_coordinate >= playing_field.get_width() || command < 1 || command > 2);
}

void Minesweeper::play_game()
{
	int x_coordinate, y_coordinate, command;
	set_mode();

	while (state != EXIT)
	{
		make_a_step(x_coordinate, y_coordinate, command);

		system("cls");

		make_a_move(x_coordinate, y_coordinate, command);

		playing_field.print();

		if (loss_condition(x_coordinate, y_coordinate))
		{
			cout << "You Lose!\n";
			state = UNINITIALIZED;
			system("pause");
		}

		if (win_condition())
		{
			cout << "You Win!\n";
			state = UNINITIALIZED;
			system("pause");
		}

		if (state == UNINITIALIZED)
		{
			system("cls");
			set_mode();
		}
	}
}

void Minesweeper::make_a_move(int x, int y, int command)
{
	if (command == 1)
	{
		playing_field.set_cell_visual_value(x, y, '!');
		return;
	}

	if (playing_field.get_cell_actual_value(x, y) == 0)
	{
		adjacent_empty_cells(x, y);
		return;
	}

	if (playing_field.get_cell_actual_value(x, y) == -1)
	{
		playing_field.set_cell_visual_value(x, y, '@');
		return;
	}
	
	playing_field.set_cell_visual_value(x, y, char(playing_field.get_cell_actual_value(x, y) + '0'));
}

void Minesweeper::adjacent_empty_cells(int x, int y)
{
	if (playing_field.get_cell_actual_value(x, y) == 0)
		playing_field.set_cell_visual_value(x, y, ' ');
	else
		playing_field.set_cell_visual_value(x, y, playing_field.get_cell_actual_value(x, y) + '0');

	if (playing_field.get_cell_actual_value(x, y) != -1 && playing_field.get_cell_actual_value(x, y) != 0)
		return;

	if (x+1 >= 0 && x+1 < playing_field.get_height() && y >= 0 && y < playing_field.get_width() && 
		playing_field.get_cell_visual_value(x+1, y) == '*')
	{
		adjacent_empty_cells(x+1, y);
	}

	if (x-1 >= 0 && x-1 < playing_field.get_height() && y >= 0 && y < playing_field.get_width() && 
		playing_field.get_cell_visual_value(x-1, y) == '*')
	{
		adjacent_empty_cells(x-1, y);
	}

	if (x >= 0 && x < playing_field.get_height() && y+1 >= 0 && y+1 < playing_field.get_width() && 
		playing_field.get_cell_visual_value(x, y+1) == '*')
	{
		adjacent_empty_cells(x, y+1);
	}

	if (x >= 0 && x < playing_field.get_height() && y-1 >= 0 && y-1 < playing_field.get_width() && 
		playing_field.get_cell_visual_value(x, y-1) == '*')
	{
		adjacent_empty_cells(x, y-1);
	}

	if (x+1 >= 0 && x+1 < playing_field.get_height() && y+1 >= 0 && y+1 < playing_field.get_width() && 
		playing_field.get_cell_visual_value(x+1, y+1) == '*')
	{
		adjacent_empty_cells(x+1, y+1);
	}

	if (x+1 >= 0 && x+1 < playing_field.get_height() && y-1 >= 0 && y-1 < playing_field.get_width() && 
		playing_field.get_cell_visual_value(x+1, y-1) == '*')
	{
		adjacent_empty_cells(x+1, y-1);
	}

	if (x-1 >= 0 && x-1 < playing_field.get_height() && y+1 >= 0 && y+1 < playing_field.get_width() && 
		playing_field.get_cell_visual_value(x-1, y+1) == '*')
	{
		adjacent_empty_cells(x-1, y+1);
	}

	if (x-1 >= 0 && x-1 < playing_field.get_height() && y-1 >= 0 && y-1 < playing_field.get_width() && 
		playing_field.get_cell_visual_value(x-1, y-1) == '*')
	{
		adjacent_empty_cells(x-1, y-1);
	}
}

void Minesweeper::menu() const
{
	cout << "=============MENU=============\n";
	cout << "|1  - Beginner(9x9)          |\n";
	cout << "|2  - Intermediate(16x16)    |\n";
	cout << "|3  - Advanced(16x30)        |\n";
	cout << "|4  - Custom                 |\n";
	cout << "|5  - Exit                   |\n";
	cout << "==============================\n";
}

void Minesweeper::flushing_cin() const
{
	cin.clear(); 
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool Minesweeper::win_condition() const
{
	for (int i = 0; i < playing_field.get_height(); i++)
	{
		for (int j = 0; j < playing_field.get_width(); j++)
			if (playing_field.get_cell_actual_value(i, j) != -1 && 
				(playing_field.get_cell_visual_value(i, j) == '*' || playing_field.get_cell_visual_value(i, j) == '!'))
				return 0;
	}
	return 1;
}

bool Minesweeper::loss_condition(int x, int y)
{
	if (playing_field.get_cell_visual_value(x, y) != '@')
		return 0;
	return 1;
}