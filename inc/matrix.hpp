#pragma once
#include <iostream>
using namespace std;

class Matrix
{
public:
	Matrix(int n, int m)
	{
		cout << "Constructor" << endl;
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
		cout << "Copy constructor" << endl;
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
		cout << "Operator = " << endl;
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
		cout << "Operator+" << endl;
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
		cout << "Operator-" << endl;
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

			cout << "Operator*" << endl;
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

	int Det2()
	{
		int det2 = -1;
		
		if ( (m_n != m_m) || ((m_n == m_m) && (m_n != 2)) )
		{
			cout << "This operation is unavailable" << endl;
		}
		else
		{
			det2 = m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1];

			return det2;
		}
		return det2;

	}
	int Det3()
	{
		
		int det3 = -1;
		
		if ((m_n != m_m) || ((m_n == m_m) && (m_n != 3)))
		{
			cout << "This operation is unavailable" << endl;
		
		}
		else
		{
			det3 = m_mat[0][0] * m_mat[1][1] * m_mat[2][2] + m_mat[0][1] * m_mat[1][2] * m_mat[2][0] + m_mat[1][0] * m_mat[2][1] * m_mat[0][2] - m_mat[2][0] * m_mat[1][1] * m_mat[0][2] - m_mat[0][1] * m_mat[1][0] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2] * m_mat[2][0];
			return det3;
		}

		return det3;
	}

	Matrix& Rev()
	{
		if (m_n == m_m)
		{
			if (m_n == 2)
			{
				
				if (Det2() != 0)
				{
					Matrix tmp(m_n, m_m);
					
					tmp.m_mat[0][0] =  m_mat[1][1] / Det2();
					tmp.m_mat[0][1] =  -m_mat[0][1] / Det2();
					tmp.m_mat[1][0] =  -m_mat[1][0] / Det2();
					tmp.m_mat[1][1] =  m_mat[0][0] / Det2();
					return tmp;
				}
				else
				{
					cout << "This operation is unavailable" << endl;
				}
			}
			else if (m_n == 3)
			{
				
				if (Det3() != 0)
				{
					Matrix tmp(m_n, m_m);

					tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[1][2] * m_mat[2][1]) / Det3();
					tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / Det3();
					tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / Det3();
					tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / Det3();
					tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / Det3();
					tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / Det3();
					tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / Det3();
					tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / Det3();
					tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / Det3();

					return tmp;
				}
				else
				{
					cout << "This operation is unavailable" << endl;
				}
			}
			else
			{
				cout << "This operation is unavailable" << endl;
			}
		}
		else
		{
			cout << "This operation is unavailable" << endl;
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
		cout << "Destructor" << endl;
		for (int i = 0; i < m_n; i++)
		{
			delete[] m_mat[i];
		}
		delete m_mat;
	}
	friend istream& operator>>(istream& in, Matrix& mat);
	friend ostream& operator<<(ostream& out, const Matrix& mat);
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
