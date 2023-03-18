// Описать макрокоманду (через директиву define), 
// проверяющую, входит ли переданное ей число (введенное с клавиатуры) 
// в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) 
// и возвращает true или false, вывести на экран «true» или «false».
//

#include <iostream>

using namespace std;

int main()
{


	//#define chislo1 chislo1
	//#define chislo2 chislo2
#define rezult(a,b) ((a>=0)and(a<=b) ? true : false)

	int chislo1;
	int chislo2;
	cout << "chislo1: ";
	cin >> chislo1;
	cout << "chislo2: ";
	cin >> chislo2;

	if (rezult(chislo1, chislo2))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}
