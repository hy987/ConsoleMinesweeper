#ifndef CHARMATRIX_H
#define CHARMATRIX_H

class CharMatrix
{
public:
	//������������
	CharMatrix();
	CharMatrix(int, int);

	//����������
	~CharMatrix();

	//��������
	void set_cell_value(int, int, char);
	void alter_matrix_size(int, int);

	//������� �� ������
	char get_cell_value(int x, int y) const
	{
		return matrix[x][y];
	}

	void print_matrix() const;

private:
	//���� �����
	char** matrix;
	int height, width;
};

#endif