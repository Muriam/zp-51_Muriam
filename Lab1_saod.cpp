#include <iostream>
#include <cstdlib>
#include <locale>
#include <conio.h>
#define SIZE 10

using namespace std;

void random_array(int array[SIZE]);
void bubble_sort(int array[SIZE], int &comparison, int &transfer);
void select_sort(int array[SIZE]);
void shaker_sort(int array[SIZE]);


int main() 
{
    setlocale(LC_ALL, "rus");
    
    int array[SIZE];
    
    int compar = 0;
    int transf = 0;
    random_array(array);
    bubble_sort(array, compar, transf); 
    for (int i = 0; i <= SIZE-1; i++) 
        cout << array[i] << " ";
    cout << "\n";    
    cout << "сравнений " << compar << endl;
    cout << "пересылок " << transf << endl;
    cout << "\n\n";

    random_array(array);
    select_sort(array); 
    for (int i = 0; i <= SIZE-1; i++) 
        cout << array[i] << " ";
    cout << "\n\n";
    
    random_array(array);
    shaker_sort(array);
    for (int i=0; i <= SIZE-1; i++)
        cout << array[i] << " ";
    cout << "\n\n";
    
     
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

void bubble_sort(int array[SIZE], int &comparison, int &transfer)
{
    cout << "\nпузырьковая сортировка" << endl;       
    for (int i = 0; i < SIZE-1; i++) 
        for (int j = SIZE-2; j >= i; j--)
	    comparison++;                        // инкремент сравнений
	    if (array[j] > array[j+1])           // если предыдущий элемент больше следующего
	    {
                int temp = array[j];             //
                array[j] = array[j+1];           // меняю их местами
		array[j+1] = temp;               //
		transfer++;                      // инкремент пересылок
	    }			
}

void select_sort(int array[SIZE])
{    
    int min, temp;
    cout << "\nсортировка методом прямого выбора" << endl;       
	for (int i = 0; i < SIZE-1; i++) 
	{ 
	    min = i;                                 // индекс минимального элемента
	    for (int j = i+1; j < SIZE; j++) 
	        if (array[j] < array[min])           // если текущий элемент меньше минимального 
                {           
		    min = j;                         // запоминаю его индекс
                }                  
	    temp = array[i];                         //
	    array[i] = array[min];                   // меняю их местами
	    array[min] = temp;                       //
	}
}

void shaker_sort(int array[SIZE])
{
    int left, right, border, temp;    
    cout << "\nшейкерная сортировка" << endl;
	for (right=SIZE-1, left=0, border=-1; border!=0;)    // устанавливаю правую и левую границы
	{
	    border = 0;
	    for (int i=left; i<right; i++)           // двигаюсь слева направо
	    {
	        if (array[i] > array[i+1])           // если текущий элемент больше следующего
		{ 
		    temp = array[i];                 // 
	            array[i] = array[i+1];           // меняю их местами
		    array[i+1] = temp;               //
		    border = i;                      // устанавливаю метку последней перестановки 
		}
	    }   
		right = border;                          // запоминаю правую границу 
		for (int i=right; i>left; i--)           // двигаюсь справа налево
		{
		    if (array[i-1] > array[i])           // если текущий элемент меньше следующего
		    {
		        temp = array[i];                 // 
			array[i] = array[i-1];           // меняю их местами
			array[i-1] = temp;	         //
			border = i;                      // устанавливаю метку последней перестановки
		    }
		}
		left = border;                           // запоминаю границу
	}
}
