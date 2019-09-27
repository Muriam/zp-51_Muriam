#include <iostream>
#include <conio.h>
#include <locale>
#include <ctime>   //для таймера
#include <cstdlib> //для генерации рандомных чисел
#define SIZE 63


using namespace std;

void random_array(int array[SIZE]);
void insertion_sort(int array[SIZE]);
void merge_sort(int array[SIZE]);


int main()
{
//    long int start_time = clock(); 		// начальное время
   
    setlocale(LC_ALL, "rus");	

    srand(time(0));        
	
    int array[SIZE];


    random_array(array);	
    insertion_sort(array);
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << "  ";
    }

    random_array(array);
	



/*
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
*/
	
    getch();
    return 0;
}


void random_array(int array[SIZE])
{
    cout << "исходный массив" << endl;
    for (int i=0; i<SIZE; i++) 
    {
        array[i] = rand()%100;
        cout << array[i] << " ";
    }
}

void insertion_sort(int array[SIZE])
{
    cout << "\nотсортировано вставками" << endl;   
    for (int i = 1; i < SIZE; i++)
    {
        int temp = array[i];
	int j = i - 1;
	while (j >= 0 && temp < array[j])
	{
            array[j + 1] = array[j];
       	    j--;
	}
	array[j + 1] = temp;
    }
}

void merge_sort(int array[SIZE])
{
	cout << "\nотсортировано слиянием" << endl; 
	
}
