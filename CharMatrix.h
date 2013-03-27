#ifndef CHARMATRIX_H
#define CHARMATRIX_H

class CharMatrix
{
public:
	//конструктори
	CharMatrix();
	CharMatrix(int, int);

	//деструктор
	~CharMatrix();

	//мутатори
	void set_cell_value(int, int, char);
	void alter_matrix_size(int, int);

	//функции за достъп
	char get_cell_value(int x, int y) const
	{
		return matrix[x][y];
	}

	void print_matrix() const;

private:
	//член данни
	char** matrix;
	int height, width;
};

#endif