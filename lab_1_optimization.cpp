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
#include <cstring>
#define SIZE 8200     
     
using std::cout;
using std::endl;

int _array1[SIZE];
int _array2[SIZE];
int n = SIZE - 1;
long int time1;

void random_array(int *array);
long int insertion_sort(int *array);
void Merge(int *array, int first, int last);        //слияние массивов
void merge_sort(int *array, int first, int last);   //рекурсивная процедура сортировки


int main()
{	

    	setlocale(LC_ALL, "rus");

    	srand(time(0));



	random_array(_array1);                 	       						//исходный массов
//	cout << "\n\n";                      



	memcpy(_array2, _array1, sizeof(int) * SIZE);          					//копия исходного массова
/*	cout << "копия исходного массива" << "\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << _array2[i] << " ";
	}
	cout << "\n";
ЗАКОММЕНТИРОВАНО, ЧТОБ ДОЛГО НЕ ЖДАТЬ ВЫВОД ОГРОМНОГО МАССИВА НА ЭКРАН */
	
	
	
	insertion_sort(_array1);                						//вызов сортировки вставками	
/*	for (int i = 0; i < SIZE; i++)
	{
		cout << _array1[i] << " ";
	}
	cout << "\n";
ЗАКОММЕНТИРОВАНО, ЧТОБ ДОЛГО НЕ ЖДАТЬ ВЫВОД ОГРОМНОГО МАССИВА НА ЭКРАН */



//	cout << "\nотсортировано слиянием" << endl;
	merge_sort(_array2, 0, n);             							//вызов сортировки слиянием
/*	for (int i = 0; i < SIZE; i++)
	{
		cout << _array2[i] << " ";
	}
	cout << "\n\n";
ЗАКОММЕНТИРОВАНО, ЧТОБ ДОЛГО НЕ ЖДАТЬ ВЫВОД ОГРОМНОГО МАССИВА НА ЭКРАН */
	
	cout << "\n" << "при размере массива = " << SIZE << " элементов" << "\n" ;
	cout << "время работы сортировки вставками = " << time1 << " мсек" << "\n\n" ;
	



	getch();
	return 0;
}


void random_array(int *array)
{
	//cout << "исходный массив" << endl;	
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = rand() % 100;
		//cout << array[i] << " ";              ЗАКОММЕНТИРОВАНО, ЧТОБ ДОЛГО НЕ ЖДАТЬ ВЫВОД ОГРОМНОГО МАССИВА НА ЭКРАН 
	}
	
}


long int insertion_sort(int *array)
{
//	cout << "\nотсортировано вставками" << endl;

long int start_time = clock(); 			// начальное время  			    //*************

	for (int i = 1; i < SIZE; i++)
	{
		const int temp = array[i];
		int j = i - 1;
		while (j >= 0 && temp < array[j])
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
	
long int end_time = clock();                    // конечное время			     //*************
time1 = end_time - start_time;                  // искомое время в мсек  		     //*************
//float time2 = (float)time1 / 1000;		// это в секундах			     //*************

return time1;															//*************	
}


void Merge(int *array, int first, int last)
{
	int middle, start, finall, j;

	int *mas = new int[SIZE];

	middle = (first + last) / 2;		//вычисление среднего элемента
	start = first; 				//начало левой части
	finall = middle + 1; 			//начало правой части

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

	delete[] mas;
}


void merge_sort(int *array, int first, int last)
{
	//cout << "\nотсортировано слиянием" << endl;
	{
		if (first < last)
		{
			merge_sort(array, first, (first + last) / 2); 		//сортировка левой части
			merge_sort(array, (first + last) / 2 + 1, last); 	//сортировка правой части
			Merge(array, first, last); 				//слияние двух частей
		}
	}
};
