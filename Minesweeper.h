#include "MineField.h"

#ifndef MINESWEEPER_H
#define MINESWEEPER_H

class Minesweeper
{
public:
	//конструктор
	Minesweeper();

	//мутатори
	void set_mode();
	void play_game();
	void make_a_move(int, int, int);
	void adjacent_empty_cells(int, int);

	//функции за достъп
	void menu() const;
	void flushing_cin() const;
	bool win_condition();
	bool loss_condition(int, int);

private:
	enum {UNINITIALIZED, INITIALIZED, EXIT} state;
	MineField playing_field;
};

#endif