#ifndef MATRIX_H
#define MATRIX_H

template <class T>
class Matrix
{
public:
	Matrix(int _height, int _width)
	{
		T filler;
		if (sizeof(T) == 4)
			filler = 0;
		else
			if (sizeof(T) == 1)
				filler = '*';

		height = _height;
		width = _width;
		matrix = new T*[height];

		for (int i = 0; i < height; i++)
		{
			matrix[i] = new T[width];
			for (int j = 0; j < width; j++)
				matrix[i][j] = filler;
		}
	}

	Matrix(const Matrix& other)
	{
		copy_matrix(other);
	}

	Matrix& operator=(const Matrix& other)
	{
		del_matrix();
		copy_matrix(other);

		return *this;
	}

	~Matrix()
	{
		del_matrix();
	}

	void set_cell_value(int x, int y, T value)
	{
		matrix[x][y] = value;
	}

	T get_cell_value(int x, int y) const
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

	void print_matrix() const
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
	}

private:
	T** matrix;
	int height, width;

	void copy_matrix(const Matrix& other)
	{
		height = other.height;
		width = other.width;

		matrix = new T*[height];
		for (int i = 0; i < height; i++)
		{
			matrix[i] = new T[width];
			for (int j = 0; j < width; j++)
				matrix[i][j] = other.matrix[i][j];
		}
	}

	void del_matrix()
	{
		for (int i = 0; i < height; i++)
			delete [] matrix[i];
		delete [] matrix;
	}
};

#endif