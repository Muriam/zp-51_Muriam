#include <iostream>
#include <conio.h>
#include <iomanip> // для setw (отступы)
#include <locale>
#include <omp.h>   //для многопоточности
#include <time.h>  //для таймера
#include <cstdlib>
#define SIZE 150



using namespace std;


void Multip(int A[SIZE][SIZE], int B[SIZE][SIZE], int AB[SIZE][SIZE]); // умножение матрицы на матрицу



int main()
{	
    int t = clock();

    omp_set_num_threads(176);
    
	setlocale(LC_ALL, "rus");
    
    srand(time(NULL)); // Инициализируем генератор случайных чисел
	
	int A[SIZE][SIZE];							   
	int B[SIZE][SIZE];
 	int i, j;
 	int AB[SIZE][SIZE];
 
	
///////////////////////////////////////////////////////////////////////////////
    
	cout << "матрица A \n\n"; 

    for (i = 0; i<SIZE; i++)          
    {	
            for (j = 0; j<SIZE; j++)      
            {
                    A[i][j] = rand() % 10;    // Каждый элемент случайное число
					cout << setw(8) << A[i][j]; 
            }
            cout << endl;
    }
        cout << endl;

///////////////////////////////////////////////////////////////////////////////
   
	cout << "матрица B \n\n"; 

    for (i = 0; i<SIZE; i++)          
    {	
            for (j = 0; j<SIZE; j++)      
            {
                    B[i][j] = rand() % 10;    // Каждый элемент случайное число от 0 до 9
					cout << setw(8) << B[i][j]; 
            }
            cout << endl;
    }
        cout << endl;

///////////////////////////////////////////////////////////////////////////////

    cout << "результат умножения \n" << endl;  
    Multip(A, B, AB);
    
	#pragma omp parallel for
    for (i = 0; i<SIZE; i++)          
    {	
            for (j = 0; j<SIZE; j++)      
            {	  		 
                    cout << setw(8) << AB[i][j]; 
            }
            cout << endl;
    }
        cout << endl;

	cout << "таймер " << clock() - t << endl;

	
    getch();
    return 0;
}

void Multip(int A[SIZE][SIZE], int B[SIZE][SIZE], int AB[SIZE][SIZE])
{
	int i, j, k;
	#pragma omp parallel for
    for (i=0; i < SIZE; i++)
    {
        for (j=0; j < SIZE; j++)
        {
        	AB[i][j] = 0;
        		for (k = 0; k < SIZE; k++)
        		{	
            		AB[i][j] += A[i][k] * B[k][j];
            	}
        }
    }
} 
