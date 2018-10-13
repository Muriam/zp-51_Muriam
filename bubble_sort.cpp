#include <iostream>
#include <cstdlib>
#include <locale>
#define SIZE 10

using namespace std;

int main() 
{
    setlocale(LC_ALL, "rus");
    
    int array[SIZE];
    int temp = 0;   
    
    cout << "исходный массив" << endl;
    for (int i=0; i<SIZE; i++) 
    {
        array[i] = rand()%100;
        cout << array[i] << " ";
    }
    
    cout << "\nпузырьковая сортировка по возрастанию" << endl;       
	int i,j;
	for (i = 0; i < SIZE-1; i++) 
		for (j = SIZE-2; j >= i; j--)
			if (array[j] > array[j+1]) 
			{
				int temp = array[j]; 
                array[j] = array[j+1]; 
				array[j+1] = temp;
			}
			      
    for (int i = 0; i <= SIZE-1; i++) 
    cout << array[i] << " ";
    cout << "\n\n";
        
    system("pause");
    return 0;
}
