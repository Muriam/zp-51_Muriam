#include <iostream>
#include <conio.h>
#include <locale>
#include <cstdlib> //для генерации рандомных чисел
#define SIZE 28

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	
	/* Алгоритм:
	int min=a[0], k=0;
	for (int i=1; i<n; i++)
	if (a[i]<min) 
		min=a[i];
	for (int i=0; i<n; i++)
 		if (a[i]==min) 
		 	k++;
	*/
	
/* 
кол-во минимальных элементов в целочисленном массиве
при временной сложности алгоритма = O(2*n) и O(n)
*/ 
	
	int Arr[SIZE];
	srand(time(0));  
	
	for (int i=0; i<SIZE; i++) 					// генерация 28 шт случайных чисел, от 0 до 100
    	{
        	Arr[i] = rand()%100;
        	cout << Arr[i] << " ";
    	}
    	cout << "\n";
	
		
	int min = Arr[0], k = 1;					// реализация алгоритма
	
    	for (int i = 1; i < SIZE; ++i)
        	if (min > Arr[i])
        	{
           		min = Arr[i];
            		k = 1;
        	}
        	else if (min == Arr[i]) 
            		++k;
 	
 	cout << "количество минимальных элементов = " << k << endl;
 	
 	
	getch();
	return 0;	
}
