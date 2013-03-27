#ifndef INTMATRIX_H
#define INTMATRIX_H

class IntMatrix
{
public:
	//������������
	IntMatrix();
	IntMatrix(int, int);

	//����������
	~IntMatrix();
	
	//��������
	void set_cell_value(int, int, int);
	void alter_matrix_size(int, int);

	//������� �� ������
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
	//���� �����
	int** matrix;
	int height, width;
};

#endif