#include <solving.hpp>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	
	cout << "Выберите метод, которым будет решаться желаемое вами уравнение: матричным методом(введите 1), или методом Крамера(введите 2):" << endl;

	int solving_way;

	cin >> solving_way;

	switch (solving_way)
	{
	case 1:
		MatrixMethod();
		break;
	case 2:
		CramerMethod();
		break;
	default:
		cout << "Такого варианта выбора нет!" << endl;
		break;
	}

	return 0;
}






