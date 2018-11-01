#include <iostream>
#include <cstdlib>
#include <locale>
#define SIZE 10

using namespace std;

int main() 
{
    setlocale(LC_ALL, "rus");
    
    int array[SIZE];
    int temp;
    int left, right, border;   
    
    cout << "исходный массив" << endl;
    for (int i=0; i<SIZE; i++) 
    {
        array[i] = rand()%100;
        cout << array[i] << " ";
    }

 	cout << "шейкерная сортировка" << endl;
	for (right=SIZE-1, left=0, border=-1; border!=0;)      // устанавливаю правую и левую границы
	{
		border = 0;
		for (int i=left; i<right; i++)               // двигаюсь слева направо
		{
			if (array[i] > array[i+1])           // если текущий элемент больше следующего
			{ 
				temp = array[i];             // 
				array[i] = array[i+1];       // меняю их местами
				array[i+1] = temp;           //
				border = i;                  // устанавливаю метку последней перестановки 
			}
		}
		right = border;                              // запоминаю правую границу 
		for (int i=right; i>left; i--)               // двигаюсь справа налево
		{
			if (array[i-1] > array[i])           // если текущий элемент меньше следующего
			{
				temp = array[i];             // 
				array[i] = array[i-1];       // меняю их местами
				array[i-1] = temp;	     //
				border = i;                  // устанавливаю метку последней перестановки
			}
		}
		left = border;                               // запоминаю границу
	}
        
    cout << "шейкерная сортировка" << endl;
    for (int i=0; i < SIZE; i++)
        cout << array[i] << " ";
    cout << "\n\n";

    system("pause");
    return 0;
}
