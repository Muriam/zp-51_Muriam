#include <iostream>
#include <cstdlib>
#include <locale>
#include <conio.h>
#define SIZE 10

using namespace std;

void random_array(int array[SIZE]);
void bubble_sort(int array[SIZE]);
void select_sort(int array[SIZE]);


int main() 
{
    setlocale(LC_ALL, "rus");
    
    int array[SIZE];
      
    random_array(array);    
    bubble_sort(array); 
    for (int i = 0; i <= SIZE-1; i++) 
        cout << array[i] << " ";
    cout << "\n\n";

    random_array(array);
    select_sort(array); 
    for (int i = 0; i <= SIZE-1; i++) 
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

void bubble_sort(int array[SIZE])
{
    int temp;
    cout << "\nпузырькова¤ сортировка" << endl;       
	for (int i = 0; i < SIZE-1; i++) 
		for (int j = SIZE-2; j >= i; j--)
			if (array[j] > array[j+1])      // если предыдущий элемент больше следующего
			{
				temp = array[j];            //
                                array[j] = array[j+1];      // меняю местами
				array[j+1] = temp;          //
			}			
}

void select_sort(int array[SIZE])
{    
    int min, temp;
    cout << "\nсортировка методом пр¤мого выбора" << endl;       
	for (int i = 0; i < SIZE-1; i++) 
	{ 
	    min = i;                           // индекс минимального элемента
	    for (int j = i+1; j < SIZE; j++) 
	        if (array[ j ] < array[min])   // если текущий элемент меньше минимального 
                {           
		     min = j;                  // запоминаю его индекс
                }                  
	    temp = array[i];         //
	    array[i] = array[min];   // меняю местами
	    array[min] = temp;       //
	}
}
