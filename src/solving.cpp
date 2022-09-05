
#include <matrix.hpp>



int MatrixMethod()
{
	cout << "������� ���������� ��������� � ����:" << endl;

	int equations;
	cin >> equations;

	cout << "������� ���������� ���������� � ����:" << endl;

	int variables;
	cin >> variables;

	if (equations != variables)
	{
		cout << "������ ���� ���������� ������ ��������� �������." << endl;

		return 1;
	}

	int size = variables;
	
	cout << "������� ������� ������������� ��� �����������:" << endl;

	Matrix coeffmat(size, size);
	cin >> coeffmat;

	cout << "������� ������ ��������� ������:" << endl;

	Matrix free(size, 1);
	cin >> free;


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((j == 0) && (coeffmat.m_mat[i][j] !=0))
			{
				cout << coeffmat.m_mat[i][j] << "*x" << j + 1;
			}
			else
			{
				if ((coeffmat.m_mat[i][j] > 0) && (coeffmat.m_mat[i][0] != 0))
				{
					cout << " + " << coeffmat.m_mat[i][j] << "*x" << j + 1;
				}
				else if ((coeffmat.m_mat[i][j] > 0) && (coeffmat.m_mat[i][0] == 0))
				{
					cout << coeffmat.m_mat[i][j] << "*x" << j + 1;
				}
				else if (coeffmat.m_mat[i][j] < 0)
				{
					cout << coeffmat.m_mat[i][j] << "*x" << j + 1 << " ";
				}
			}
		}
		cout << "= " << free.m_mat[i][0] << endl;

	}

	cout << "������� ������������ �����:" << endl;

	double determinant0 = coeffmat.Determinant();

	if (determinant0 == 0)
	{
		cout << "0, ����� ������� ������ ���� ������ ������ ��������� �������." << endl;

		return 2;
	}
	else
	{
		cout << determinant0 << endl;
	}

	Matrix X = coeffmat.Inversed() * free;

	cout << "�������� ������ ���� ����� �������� ������ ������, ��������� �� ����������:" << endl;

	cout << "������ �:" << endl;

	cout << X << endl;

	cout << "��� � ���� ������:" << endl;

	cout << "(";
	
	for (int i = 0; i < size - 1; i++)
	{
		cout << "x" << i + 1 << " = " << X.m_mat[i][0] << "; ";
	}
	cout << "x" << size << " = " << X.m_mat[size-1][0] << ")" << endl;

	return 3;
}



int CramerMethod()
{
	cout << "������� ���������� ��������� � ����:" << endl;

	int equations;
	cin >> equations;

	cout << "������� ���������� ���������� � ����:" << endl;

	int variables;
	cin >> variables;

	if (equations != variables)
	{
		cout << "������ ���� ���������� ������ ������� �������." << endl;

		return 4;
	}

	int size = variables;

	cout << "������� ������� ������������� ��� �����������:" << endl;

	Matrix coeffmat(size, size);
	cin >> coeffmat;

	cout << "������� ������ ��������� ������:" << endl;

	Matrix free(size, 1);
	cin >> free;


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((j == 0) && (coeffmat.m_mat[i][j] != 0))
			{
				cout << coeffmat.m_mat[i][j] << "*x" << j + 1;
			}
			else
			{
				if ((coeffmat.m_mat[i][j] > 0) && (coeffmat.m_mat[i][0] != 0))
				{
					cout << " + " << coeffmat.m_mat[i][j] << "*x" << j + 1;
				}
				else if ((coeffmat.m_mat[i][j] > 0) && (coeffmat.m_mat[i][0] == 0))
				{
					cout << coeffmat.m_mat[i][j] << "*x" << j + 1;
				}
				else if (coeffmat.m_mat[i][j] < 0)
				{
					cout << coeffmat.m_mat[i][j] << "*x" << j + 1 << " ";
				}
			}
		}
		cout << "= " << free.m_mat[i][0] << endl;

	}

	cout << "������� ������������ �����:" << endl;

	double determinant0 = coeffmat.Determinant();
		
	cout << determinant0 << endl;

	Matrix X(size, 1);

	Matrix A = coeffmat;

	cout << "��������������� ������������:" << endl;

	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
		{
			A.m_mat[i][j] = free.m_mat[i][0];
		}
		X.m_mat[j][0] = A.Determinant();

		cout << "delta_x" << j+1 << " = " << X.m_mat[j][0] << endl;
	}

	int flag = 0;

	for (int i = 0; i < size; i++)
	{
		if (X.m_mat[i][0] != 0)
		{
			flag = 1;
		}
	}

	if ((determinant0 == 0) && (flag == 0))
	{
		cout << "�. �. ��� ��������������� ������������ ����� 0, ������ ���� ����� ����������� ��������� �������." << endl;
		return 01;
	}
	else if ((determinant0 == 0) && (flag == 1))
	{
		cout << "�. �. ���� �� ��������������� ������������� �� ����� 0, ������ ���� �� ����� ������� �����." << endl;

		return 02;
	}

	for (int i = 0; i < size; i++)
	{
		X.m_mat[i][0] /= determinant0;
	}


	cout << "�������� ������ ���� ����� �������� ������ ����� ����������:" << endl;

	cout << "(";

	for (int i = 0; i < size - 1; i++)
	{
		cout << "x" << i + 1 << " = " << X.m_mat[i][0] << "; ";
	}
	cout << "x" << size << " = " << X.m_mat[size - 1][0] << ")" << endl;

	return 03;
}
