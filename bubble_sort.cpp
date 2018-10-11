#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <locale>
#define SIZE 10

using namespace std;

int main() 
{
    setlocale(LC_ALL, "rus");
    
    int array[SIZE];
    int temp = 0;
    
    srand(time(NULL));
    
    cout << "èñõîäíûé ìàññèâ" << endl;
    for(int i=0; i<=SIZE-1; i++) 
    {
        array[i] = rand()%100;
        cout << array[i] << " ";
    }
    
    cout << "\n\nïóçûðüêîâàÿ ñîðòèðîâêà ïî âîçðàñòàíèþ" << endl;   
    for (int i = 0; i < SIZE-1; i++)
    {
        if (array[i] > array[i+1])
        {
            temp = array[i];     
            array[i] = array[i+1]; 
            array[i+1] = temp;    
        }
    }
    for(int i=0; i <= SIZE-1; i++) 
       cout << array[i] << " ";
    
        
    getch();
    return 0;
}
