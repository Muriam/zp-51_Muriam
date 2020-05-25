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
		при временной сложности алгоритма = O(2*n)
	*/ 
	
	int Arr[SIZE];
	srand(time(0));  
	
	for (int i=0; i<SIZE; i++) 					// генерация 28 шт случайных чисел, от 0 до 100
    	{
        	Arr[i] = rand()%100;
        	cout << Arr[i] << " ";
    	}
    	cout << "\n";
	
		
	int min = Arr[0], k = 0;					// реализация алгоритма
	
	for (int i = 1; i < SIZE; i++)
 		if (Arr[i] < min) 
		 	min = Arr[i];
		 	
	for (int i = 0; i < SIZE; i++)
 		if (Arr[i] == min) 
		 	k++;
 	
 	cout << "количество минимальных элементов = " << k << endl;
 	cout << "\n\n";
 	
 	/* 
		найти кол-во минимальных элементов в целочисленном массиве
		при временной сложности алгоритма = O(n)
	*/ 
 	
	
	getch();
	return 0;	
}
