#include "IntMatrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

IntMatrix::IntMatrix()
{
	//matrix = NULL;
}

IntMatrix::IntMatrix(int _height, int _width)
{
	height = _height;
	width = _width;
	matrix = new int*[height];

	for (int i = 0; i < height; i++)
	{
		matrix[i] =  new int[width];
		for (int j = 0; j < width; j++)
			matrix[i][j] = 0;
	}
}

IntMatrix::~IntMatrix()
{
	for (int i = 0; i < height; i++)
		delete [] matrix[i];
	delete [] matrix;
}

void IntMatrix::set_cell_value(int x, int y, int value)
{
	matrix[x][y] = value;
}

void IntMatrix::alter_matrix_size(int new_height, int new_width)
{
	if (matrix)
	{
		for (int i = 0; i < height; i++)
			delete [] matrix[i];
		delete [] matrix;
	}

	height = new_height;
	width = new_width;

	matrix = new int*[height];
	for (int i = 0; i < height; i++)
	{
		matrix[i] = new int[width];
		for (int j = 0; j < width; j++)
			matrix[i][j] = 0;
	}
}

void IntMatrix::print_matrix() const
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cout << setw(2) << matrix[i][j] << " ";
		cout << endl;
	}
}