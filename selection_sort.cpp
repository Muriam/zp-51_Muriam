#include <iostream>
#include <cstdlib>
#include <locale>
#define SIZE 10

using namespace std;

int main() 
{
    setlocale(LC_ALL, "rus");
    
    int array[SIZE];
    int min, temp;   
    
    cout << "исходный массив" << endl;
    for (int i=0; i<SIZE; i++) 
    {
        array[i] = rand()%100;
        cout << array[i] << " ";
    }
    
    cout << "\nсортировка методом пр¤мого выбора" << endl;       
	  for (int i = 0; i < SIZE-1; i++) 
	  { 
		    min = i;                            // индекс минимального элемента
		    for (int j = i+1; j < SIZE; j++) 
		        if (array[ j ] < array[min])    // если текущий элемент меньше минимального
		            min = j;                    // запоминаю его индекс
		            temp = array[i];            //
		            array[i] = array[min];      // меняю местами
		            array[min] = temp;          //
	  }
			      
    for (int i = 0; i <= SIZE-1; i++) 
		cout << array[i] << " ";
    cout << "\n\n";
        
    system("pause");
    return 0;
}
