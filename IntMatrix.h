#ifndef INTMATRIX_H
#define INTMATRIX_H

class IntMatrix
{
public:
	//конструктори
	IntMatrix();
	IntMatrix(int, int);

	//деструктор
	~IntMatrix();
	
	//мутатори
	void set_cell_value(int, int, int);
	void alter_matrix_size(int, int);

	//функции за достъп
	int get_cell_value(int x, int y) const
	{
		return matrix[x][y];
	}

	int get_height() const
	{
		return height;
	}

	int get_width() const
	{
		return width;
	}

	void print_matrix() const;

private:
	//член данни
	int** matrix;
	int height, width;
};

#endif