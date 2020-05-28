#include <iostream>
#include <conio.h>
#include <locale>

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	
	/* Алгоритм:
	double s=0; int n=3, m=10;
	for (int i=1; i<=m; i++)
	s+=i*n;
	*/	
  
  
	/* 
	Поиск суммы элементов последовательности n, 2*n, …, m*n
	при временной сложности алгоритма = O(n)
	*/ 
	 
	int m = 10, n = 3; 
	double s = 0;
	
	for (int i = 1; i <= m; i++) 					// реализация алгоритма
  	{	
		cout << i * n << " ";
		s += i * n;		
  	}
  	cout << "\n\n";
	
	cout << "сумма элементов последовательнсти = " << s << "\n\n";
		
 	
 	/* 
	Найти сумму элементов последовательнсти
	при временной сложности алгоритма = O(1)
	*/ 
 	
	
	getch();
	return 0;	
}
