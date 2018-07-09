#include <iostream>
//#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <QtDebug>
#define SIZE 10


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL)); // Инициализируем генератор случайных чисел

    int A[SIZE],i;


        qDebug() << "рандомный массив \n\n";
        for (i = 0; i<SIZE; i++)
        {    
             A[i] = rand() % 100;    // Каждый элемент - случайное число от 0 до 100
             qDebug() << /*setw(4) <<*/ A[i];
        }
            qDebug() << endl;


    return 0;
}
