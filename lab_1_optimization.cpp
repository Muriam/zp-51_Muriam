/* 
*  1. Написать программу, которая реализует сортировки: вставками и слиянием.
*  2. Проверить правильность работы программы на нескольких тестовых наборах входных данных. 
*  3. Выбрать размерность массива N такой, чтобы время работы программы более медленным алгоритмом было порядка 5 секунд. 
*  4. Оценить (на 5-10 тестах) относительное быстродействие алгоритмов (сортировок).
*/

#include <iostream>
#include <conio.h>
#include <locale>
#include <ctime>   //для таймера
#include <cstdlib> //для генерации рандомных чисел
#define SIZE 63


using namespace std;

void random_array(int array[SIZE]);
void insertion_sort(int array[SIZE]);
//void merge_sort(int array[SIZE]);
void Merge(int array[SIZE], int first, int last); 	//слияние массивов 
void MergeSort(int array[SIZE], int first, int last);	//рекурсивная процедура сортировки

int array[SIZE];
int array2[SIZE];



int main()
{
//    long int start_time = clock(); 		//начальное время
   
    setlocale(LC_ALL, "rus");	

    srand(time(0));        
	   
    int n;


    random_array(array);	
    insertion_sort(array);               //вызов сортировки вставками
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << "  ";
    }

    
//	random_array(array2);
    cout << endl;
    MergeSort(array2, 1, n);             //вызов сортировки слиянием
    for (int i = 0; i < SIZE; i++)
    {
        cout << array2[i] << "  ";
    }




/*	
    long int end_time = clock();                    // конечное время	
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


void Merge(int array[SIZE], int first, int last)
{
    cout << "\nотсортировано слиянием" << endl; 
	
    int middle, start, finall, j;
	
    int *mas = new int[];
	
    middle = (first + last) / 2;	//вычисление среднего элемента
    start = first; 			//начало левой части
    finall = middle + 1; 		//начало правой части
	
    for (j = first; j <= last; j++) 	//выполнять от начала до конца
        if ((start <= middle) && ((finall > last) || (array[start] < array[finall])))
	{
	    mas[j] = array[start];
	    start++;
	}
	else
        {
	    mas[j] = array[finall];
	    finall++;
	}
	
    //возвращение результата в список
    for (j = first; j <= last; j++) 
        array[j] = mas[j];
	
    delete [] mas;	
}


void MergeSort(int array[SIZE], int first, int last)
{
    {
        if (first < last)
	{
	    MergeSort(array, first, (first+last)/2);      //сортировка левой части
       	    MergeSort(array, (first+last)/2+1, last);     //сортировка правой части
	    Merge(array, first, last); 		          //слияние двух частей
	}
    }
};
