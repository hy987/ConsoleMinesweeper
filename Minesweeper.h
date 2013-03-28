#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "MineField.h"

class Minesweeper
{
public:
	Minesweeper();

	void play_game();

private:
	enum {UNINITIALIZED, INITIALIZED, EXIT} state;
	MineField playing_field;

	void set_mode();
	void make_a_step(int&, int&, int&) const;
	void make_a_move(int, int, int);
	void adjacent_empty_cells(int, int);

	void menu() const;
	void flushing_cin() const;
	bool win_condition() const;
	bool loss_condition(int, int);
};

#endif