/*Отсортировать список: пузырьковой, методом прямого выбора, и шейкерной сортировками. Подчситать кол-во сравнений и пересылок*/
#include <iostream>
#include <cstdlib>
#include <locale>
#include <conio.h>
#define SIZE 10

using namespace std;

void random_array(int array[SIZE]);
void bubble_sort(int array[SIZE], int &comparison, int &transfer);
void select_sort(int array[SIZE], int &comparison2, int &transfer2);
void shaker_sort(int array[SIZE]);


int main() 
{
    setlocale(LC_ALL, "rus");
	
    srand(time(0));  			// при каждом новом запуске программы генерирует другие случайные числа
    
    int array[SIZE];
    
    int compar = 0;
    int transf = 0;
    int compar2 = 0;
    int transf2 = 0;
	
    random_array(array);
    bubble_sort(array, compar, transf); 
    for (int i = 0; i <= SIZE-1; i++) 
        cout << array[i] << " ";
    cout << "\n";    
    cout << "сравнений " << compar << endl;
    cout << "пересылок " << transf << endl;
    cout << "\n\n";

    random_array(array);
    select_sort(array, compar2, transf2);  
    for (int i = 0; i <= SIZE-1; i++) 
        cout << array[i] << " ";
    cout << "\n";    
    cout << "сравнений " << compar2 << endl;
    cout << "пересылок " << transf2 << endl;
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
    {
        for (int j = SIZE-2; j >= i; j--)
	{    
	    comparison++;                            // инкремент сравнений
	    if (array[j] > array[j+1])               // если предыдущий элемент больше следующего
	    {
                int temp = array[j];                 //
                array[j] = array[j+1];               // меняю их местами
		array[j+1] = temp;                   //
		transfer++;                          // инкремент пересылок
	    }
	}
    }
}


/*
1. Выбираем элемент с min значением и помещаем в a[0]
2. Снова выбираем элемент с min значением из оставшихся несортированных элементов и помещаем его в a[1]
3. И т.д., с каждым несортированным элементом, до конца. 
*/
void select_sort(int array[SIZE], int &comparison2, int &transfer2)
{    
    int min, temp;
	
    cout << "\nсортировка методом прямого выбора" << endl;       
    for (int i = 0; i < SIZE-1; i++) 
    { 
        min = i;                                     // присваивание min индекса минимального элемента
		
        for (int j = i+1; j < SIZE; j++)
	{
	    if (array[j] < array[min]) min = j;      // если текущий элемент меньше минимального, запоминаю его индекс
	}
	    
	if (min == i) continue; 
	temp = array[i];                             //
	array[i] = array[min];                       // меняю их местами
	array[min] = temp;                           //
	transfer2++;			             // инкремент пересылок
    }
    comparison2 = ((SIZE * SIZE) - SIZE) / 2;        // сравнений
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
