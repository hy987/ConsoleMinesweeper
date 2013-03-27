#include "CharMatrix.h"
#include <iostream>
using namespace std;

CharMatrix::CharMatrix()
{
	//matrix = NULL;
}

CharMatrix::CharMatrix(int _height, int _width)
{
	height = _height;
	width = _width;
	matrix = new char*[height];

	for (int i = 0; i < height; i++)
	{
		matrix[i] = new char[width];
		for (int j = 0; j < width; j++)
			matrix[i][j] = '*';
	}
}

CharMatrix::~CharMatrix()
{
	for (int i = 0; i < height; i++)
		delete [] matrix[i];
	delete [] matrix;
}

void CharMatrix::set_cell_value(int x, int y, char symbol)
{
	matrix[x][y] = symbol;
}

void CharMatrix::alter_matrix_size(int new_height, int new_width)
{
	if(matrix)
	{
		for (int i = 0; i < height; i++)
			delete [] matrix[i];
		delete [] matrix;
	}

	height = new_height;
	width = new_width;

	matrix = new char*[height];
	for (int i = 0; i < height; i++)
	{
		matrix[i] = new char[width];
		for (int j = 0; j < width; j++)
			matrix[i][j] = '*';
	}

}

void CharMatrix::print_matrix() const
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}