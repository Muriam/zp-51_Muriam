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
  

	
/* Поиск суммы элементов последовательности n, 2*n, …, m*n */ 
	
	 
	int m = 10, n = 3; 
	double s = 0;
	
	for (int i = 1; i <= m; i++) 					// реализация алгоритма 1
  	{	
		cout << i * n << " ";
		s += i * n;		
  	}
  	cout << "\n\n";
	
 	cout << "сумма элементов последовательнсти O(n) = " << s << "\n\n";
		
 	
 
 	s2 = n * (1 + m) * m / 2;					// реализация алгоритма 2
     	cout << "сумма элементов последовательнсти O(1) = " << s2;   
	
	getch();
	return 0;	
}
