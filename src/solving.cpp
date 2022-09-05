
#include <matrix.hpp>



int MatrixMethod()
{
	cout << "Введите количество уравнений В СЛАУ:" << endl;

	int equations;
	cin >> equations;

	cout << "Введите количество переменных В СЛАУ:" << endl;

	int variables;
	cin >> variables;

	if (equations != variables)
	{
		cout << "Данную СЛАУ невозможно решить матричным методом." << endl;

		return 1;
	}

	int size = variables;
	
	cout << "Введите матрицу коэффициентов при неизвестных:" << endl;

	Matrix coeffmat(size, size);
	cin >> coeffmat;

	cout << "Введите вектор свободных членов:" << endl;

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

	cout << "Главный определитель равен:" << endl;

	double determinant0 = coeffmat.Determinant();

	if (determinant0 == 0)
	{
		cout << "0, таким образом данную СЛАУ нельзя решить матричным методом." << endl;

		return 2;
	}
	else
	{
		cout << determinant0 << endl;
	}

	Matrix X = coeffmat.Inversed() * free;

	cout << "Решением данной СЛАУ будет являться данный вектор, состоящий из переменных:" << endl;

	cout << "Вектор Х:" << endl;

	cout << X << endl;

	cout << "Или в виде набора:" << endl;

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
	cout << "Введите количество уравнений В СЛАУ:" << endl;

	int equations;
	cin >> equations;

	cout << "Введите количество переменных В СЛАУ:" << endl;

	int variables;
	cin >> variables;

	if (equations != variables)
	{
		cout << "Данную СЛАУ невозможно решить методом Крамера." << endl;

		return 4;
	}

	int size = variables;

	cout << "Введите матрицу коэффициентов при неизвестных:" << endl;

	Matrix coeffmat(size, size);
	cin >> coeffmat;

	cout << "Введите вектор свободных членов:" << endl;

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

	cout << "Главный определитель равен:" << endl;

	double determinant0 = coeffmat.Determinant();
		
	cout << determinant0 << endl;

	Matrix X(size, 1);

	Matrix A = coeffmat;

	cout << "Вспомогательные определители:" << endl;

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
		cout << "Т. к. все вспомогательные определители равны 0, данная СЛАУ имеет бесконечное множество решений." << endl;
		return 01;
	}
	else if ((determinant0 == 0) && (flag == 1))
	{
		cout << "Т. к. один из вспомогательных определителей не равен 0, данная СЛАУ не имеет решений вовсе." << endl;

		return 02;
	}

	for (int i = 0; i < size; i++)
	{
		X.m_mat[i][0] /= determinant0;
	}


	cout << "Решением данной СЛАУ будет являться данный набор переменных:" << endl;

	cout << "(";

	for (int i = 0; i < size - 1; i++)
	{
		cout << "x" << i + 1 << " = " << X.m_mat[i][0] << "; ";
	}
	cout << "x" << size << " = " << X.m_mat[size - 1][0] << ")" << endl;

	return 03;
}
