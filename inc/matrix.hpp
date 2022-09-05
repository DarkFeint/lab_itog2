#pragma once
#include <iostream>
using namespace std;

class Matrix
{
public:
	Matrix(int n, int m)
	{
		//cout << "Constructor" << endl;
		m_n = n;
		m_m = m;
		m_mat = new double* [m_n];
		for (int i = 0; i < m_n; i++)
		{
			m_mat[i] = new double[m_m];
		}
	}
	
 
	Matrix(const Matrix& mat)
	{
		//cout << "Copy constructor" << endl;
		m_n = mat.m_n;
		m_m = mat.m_m;
		m_mat = new double* [m_n];
		for (int i = 0; i < m_n; i++)
		{
			m_mat[i] = new double[m_m];
		}
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				m_mat[i][j] = mat.m_mat[i][j];
			}
		}
	}
	Matrix& operator=(const Matrix& mat)
	{
		//cout << "Operator = " << endl;
		m_n = mat.m_n;
		m_m = mat.m_m;
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				m_mat[i][j] = mat.m_mat[i][j];
			}
		}
		return *this;
	}
	Matrix operator+(const Matrix& mat)
	{
		//cout << "Operator+" << endl;
		Matrix tmp(m_n, m_m);
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
			}
		}
		return tmp;
	}
	Matrix operator-(const Matrix& mat)
	{
		//cout << "Operator-" << endl;
		Matrix tmp(m_n, m_m);
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
			}
		}
		return tmp;
	}

	Matrix operator*(const Matrix& mat)
	{
		if (m_m == mat.m_n)
		{

			//cout << "Operator*" << endl;
			Matrix tmp(m_n, mat.m_m);

			for (int i = 0; i < m_n; i++)
			{
				for (int j = 0; j < mat.m_m; j++)
				{
					tmp.m_mat[i][j] = 0;
				}
			}

			for (int i = 0; i < m_n; i++)
			{
				for (int j = 0; j < mat.m_m; j++)
				{
					for (int k = 0; k < m_m; k++)
					{
						tmp.m_mat[i][j] += m_mat[i][k] * mat.m_mat[k][j];
					}
					
				}
			}
			return tmp;
		}
		else
		{
			cout << "This operation is unavailable" << endl;
		}
	}

	Matrix& get()
	{
		return *this;
	}

	int getelement(int i, int j)
	{
		return m_mat[i][j];
	}

	Matrix Minor(int row, int col)
	{
		
		if (m_n == m_m)
		{
			int size = m_n;

			Matrix minor(size - 1, size - 1);

			if (size > 1)
			{

				int offsetRow = 0;
				int offsetCol = 0;
				for (int i = 0; i < size - 1; i++)
				{
					
					if (i == row)
					{
						offsetRow = 1;
					}

					offsetCol = 0;
					for (int j = 0; j < size - 1; j++)
					{

						if (j == col)
						{
							offsetCol = 1;
						}

						minor.m_mat[i][j] = m_mat[i + offsetRow][j + offsetCol];
					}
				}

				return minor;
			}
			else
			{
				return *this;
			}
		}
		else
		{
			cout << "Это не квадратная матрица!" << endl;
		}
	}

	double Determinant()
	{
		if (m_n == m_m)
		{
			int size = m_n;

			double det = 0;
			double sign = 1.0;
			
			
			if (size == 1) 
			{
				return m_mat[0][0];
			}
			else if (size == 2) 
			{
				return m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
			}
			else 
			{
				for (int j = 0; j < size; j++) 
				{
					
					det = det + sign * m_mat[0][j] * Minor(0, j).Determinant();
					
					sign = -sign;
				}

			}

			return det;
		}
		else
		{
			cout << "Это не квадратная матрица!" << endl;
		}
	}

	Matrix Inversed()
	{
		if (m_n == m_m)
		{
			int size = m_n;

			double det0 = Determinant();

			if (det0 != 0)
			{
				Matrix inv(size, size);

				double sign = 1.0;

				for (int i = 0; i < size; i++)
				{
					for (int j = 0; j < size; j++)
					{
							if ((i + j) % 2 != 0)
							{
								inv.m_mat[j][i] = Minor(i, j).Determinant() * (-sign)/ Determinant();
							}
							else
							{
								inv.m_mat[j][i] = Minor(i, j).Determinant() * sign / Determinant();
							}
					}
				}

				return inv;
			}
			else
			{
				cout << "Это вырожденная матрица!" << endl;
			}
			
		}
		else
		{
			cout << "Это не квадратная матрица!" << endl;
		}

	}
	

	Matrix& Transpon()
	{
		
		
		int n = m_n;

		int m = m_m;
		
		if (m_n > m_m)
		{
			
			for (int i = 0; i < m_n; i++)
			{
				m_mat[i] = (double*) realloc(m_mat[i], n * sizeof(double));
			}
			for (int i = 0; i < m_n; i++)
			{
				for (int j = 0; j < m_n; j++)
				{
					
					if (i < j)
					{
						swap(m_mat[i][j], m_mat[j][i]);
					}
				}
			}

			m_mat = (double**)realloc(m_mat, m * sizeof(double));

			m_m = n;

			m_n = m;
		}
		else if (m_m > m_n)
		{
			m_mat = (double**)realloc(m_mat, m * sizeof(double));

			for (int i = 0; i < m_m; i++)
			{
				for (int j = 0; j < m_m; j++)
				{
					
					if (i < j)
					{
						swap(m_mat[i][j], m_mat[j][i]);
					}
				}
			}
			for (int i = 0; i < m_n; i++)
			{
				m_mat[i] = (double*)realloc(m_mat[i], n * sizeof(double));
				
			}

			m_n = m;
			m_m = n;
		}
		else if (m_n == m_m)
		{
			
			
			for (int i = 0; i < m_n; i++)
			{
				for (int j = 0; j < m_n; j++)
				{
					
					if (i < j)
					{
						swap(m_mat[i][j], m_mat[j][i]);
					}
				}
			}
		}

		return get();
	}

	
	~Matrix()
	{
		//cout << "Destructor" << endl;
		for (int i = 0; i < m_n; i++)
		{
			delete[] m_mat[i];
		}
		delete m_mat;
	}
	friend istream& operator>>(istream& in, Matrix& mat);
	friend ostream& operator<<(ostream& out, const Matrix& mat);
	friend int MatrixMethod();
	friend int CramerMethod();
private:
	int m_n, m_m;
	double** m_mat;
};
istream& operator>>(istream& in, Matrix& mat)
{
	for (int i = 0; i < mat.m_n; i++)
	{
		for (int j = 0; j < mat.m_m; j++)
		{
			in >> mat.m_mat[i][j];
		}
	}
	return in;
}
ostream& operator<<(ostream& out, const Matrix& mat)
{
	out << "Matrix " << mat.m_n << "x" << mat.m_m << endl;
	for (int i = 0; i < mat.m_n; i++)
	{
		for (int j = 0; j < mat.m_m; j++)
		{
			out << mat.m_mat[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

