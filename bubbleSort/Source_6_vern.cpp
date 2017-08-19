#include <iostream>
#include <conio.h>
#include <cstring> //для ф-ции strcmp
#define N 8


using namespace std;

/*структура базы данных*/
struct dataBase
{
	char name[33];
	unsigned short int sumContribution;
	char date[9];
	char advocate[23];
};


/*прототипы*/
bool ReadBase(struct dataBase *p, int* indArr, int* indArr2);
int output(dataBase *db, int* indArr);
int bubbleSortName(dataBase *db, int* indArr);
int bubbleSortSum(dataBase *db, int* indArr);


/* чтение базы из файла */
bool ReadBase(dataBase *p, int* indArr, int* indArr2) //указатель на переменную с типом структуры, указатель на индексные массивы
{
	FILE *base = fopen("base3.dat", "rb");
	if (base == NULL) { cout << "ошибка!" << endl; return 1; }
	for (int i = 0, advSize = 22, nameSize = 32, dateSize = 8; i<N; i++)
	{
		fread(p[i].name, sizeof(char), nameSize, base);  //(где 1 - количество ячеек пам¤ти, 32 - количество символов в ячейках)
		fread(&(p[i].sumContribution), sizeof(unsigned short int), 1, base);
		fread(p[i].date, sizeof(char), dateSize, base);
		fread(p[i].advocate, sizeof(char), advSize, base);
		p[i].name[nameSize] = 0;
		p[i].advocate[advSize] = 0;
		p[i].date[dateSize] = 0;
		indArr[i] = i; //создание индексного массива
		indArr2[i] = i; //создание индексного массива2
	}
	fclose(base);
	return 0;
}

/* вывод на экран */ 
int output(dataBase *db, int* indArr)
{

	for (int i = 0; i<N; i++)
	{
		int pos = indArr[i];
		cout << db[pos].name << "\t" << db[pos].sumContribution << "\t" << db[pos].date << "\t" << db[pos].advocate << endl;

	}

	cout << "_______________________________________________________________________________" << "\n" << endl;

	return 0;
}


/* сортировка методом пузырька по фамилии вкладчика (name) */
int bubbleSortName(dataBase *db, int* indArr)
{
	int temp;
	for (int i = 0; i<N - 1; i++)
	{
		for (int j = 0; j<N - 1 - i; j++)
			if (strcmp(db[indArr[j]].name, db[indArr[j + 1]].name)>0) //сравниваем элементы массива, через индексный массив
			{
				// меняем элементы местами. Элементы массива db фактически не перемещаются, но мы меняем их порядок в индексном массиве.
				temp = indArr[j];
				indArr[j] = indArr[j + 1];
				indArr[j + 1] = temp;
			}

	}

	return 0;
}


/* сортировка методом пузырька по сумме вклада (sumContribution) */
int bubbleSortSum(dataBase *db, int* indArr)
{
	int temp2;
	for (int i = 0; i<N-1; i++)
	{
		for (int j = 0; j<N-1; j++)
			if (db[indArr[j]].sumContribution > db[indArr[j + 1]].sumContribution) //сравниваем элементы массива, через индексный массив 
		 
			{
				// меняем элементы местами. Элементы массива db фактически не перемещаются, но мы меняем их порядок в индексном массиве
				temp2 = indArr[j];
				indArr[j] = indArr[j + 1];
				indArr[j + 1] = temp2;
			}

	}
	
	return 0;	
}


int main()
{		
	dataBase* db = new dataBase[N]; //создание динамического массива db
	int* indArr = new int[N]; //индексный массив динамический indArr
	int* indArr2 = new int[N]; //индексный массив динамический indArr2

	/* вызов функции чтения из файла */
	ReadBase(db, indArr, indArr2); 
	/* вывод на экран */
	output(db, indArr);  

	
	/* вызов функции сортировки пузырьком по имени */
	bubbleSortName(db, indArr); 	
	/* вывод на экран */
	output(db, indArr);  

	
	/* вызов функции сортировки пузырьком по сумме вклада */
	bubbleSortSum(db, indArr2); 
	/* вывод на экран */
	output(db, indArr2);
	


	delete [] db;
	getch();
	return 0;
}

