#include <iostream>
#include <conio.h>
#include <locale>

using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");
    
    int n;
    cout << "\n¬ведите длину вашего массива: ";
    cin >> n;
    int Array[n];
    cout << "\nвведите любые " << n << " чисел для вашего несортированного массива: ";

    for (int i = 0; i < n; i++)
    {
        cin >> Array[i];
    }

    //сортировка вставками
    for (int i = 1; i < n; i++)
    {
        int temp = Array[i];
	int j = i - 1;
	while (j >= 0 && temp < Array[j])
	{
	    Array[j + 1] = Array[j];
	    j--;
	}
	Array[j + 1] = temp;
    }

    cout << "\nотсорировано вставками: ";
    for (int i = 0; i < n; i++)
    {
        cout << Array[i] << "\t";
    }
	
    getch();
    return 0;
}
