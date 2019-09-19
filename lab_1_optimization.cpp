#include <iostream>
#include <conio.h>
#include <locale>
#include <ctime>   //для таймера
#include <cstdlib> //для генерации рандомных чисел
#define SIZE 6300


using namespace std;


int main()
{
    long int start_time = clock(); 		// начальное время
   
    setlocale(LC_ALL, "rus");	

    srand(time(0));        
	
    int Array[SIZE];


    cout << "\nИсходный массив: ";
    for (int i = 0; i < SIZE; i++)
    {
        Array[i] = rand()%100;
	cout << Array[i] << "  ";
    }

/* сортировка вставками */
    for (int i = 1; i < SIZE; i++)
    {
	int temp = Array[i];
	int j = i - 1;
	while (j >= 0 && temp < Array[j])
	{
            Array[j + 1] = Array[j];
       	    j--;
	}
	Array[j + 1] = temp;
    }

    cout << "\nОтсортированный массив: ";
    for (int i = 0; i < SIZE; i++)
    {
	cout << Array[i] << "  ";
    }
	
    long int end_time = clock();                   // конечное время	
    long int time1 = end_time - start_time;         // искомое время	
    cout << "\n" << "Время работы программы " << time1 << " миллисекунд";
    float time2 = (float)time1 / 1000;
    cout << "\n" << "То есть, это составляет " << time2 << " секунд";
	
    getch();
    return 0;
}
