#include <iostream>
#include <conio.h>
#include <cstring> //��� �-��� strcmp
#define N 8


using namespace std;

/*��������� ���� ������*/
struct dataBase
{
	char name[33];
	unsigned short int sumContribution;
	char date[9];
	char advocate[23];
};


/*���������*/
bool ReadBase(struct dataBase *p, int* indArr, int* indArr2);
int output(dataBase *db, int* indArr);
int bubbleSortName(dataBase *db, int* indArr);
int bubbleSortSum(dataBase *db, int* indArr);


/* ������ ���� �� ����� */
bool ReadBase(dataBase *p, int* indArr, int* indArr2) //��������� �� ���������� � ����� ���������, ��������� �� ��������� �������
{
	FILE *base = fopen("base3.dat", "rb");
	if (base == NULL) { cout << "������!" << endl; return 1; }
	for (int i = 0, advSize = 22, nameSize = 32, dateSize = 8; i<N; i++)
	{
		fread(p[i].name, sizeof(char), nameSize, base);  //(��� 1 - ���������� ����� ������, 32 - ���������� �������� � �������) 
		fread(&(p[i].sumContribution), sizeof(unsigned short int), 1, base);
		fread(p[i].date, sizeof(char), dateSize, base);
		fread(p[i].advocate, sizeof(char), advSize, base);
		p[i].name[nameSize] = 0;
		p[i].advocate[advSize] = 0;
		p[i].date[dateSize] = 0;
		indArr[i] = i;//�������� ���������� �������
		indArr2[i] = i; //�������� ���������� �������2
	}
	fclose(base);
	return 0;
}

/* ����� �� ����� */
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


/* ���������� ������� �������� �� ������� ��������� (name) */
int bubbleSortName(dataBase *db, int* indArr)
{
	int temp;
	for (int i = 0; i<N - 1; i++)
	{
		for (int j = 0; j<N - 1 - i; j++)
			if (strcmp(db[indArr[j]].name, db[indArr[j + 1]].name)>0)    //���������� �������� �������, ����� ��������� ������
			{
				// ������ �������� �������. �������� ������� db ���������� �� ������������, �� �� ������ �� ������� � ��������� �������.
				temp = indArr[j];
				indArr[j] = indArr[j + 1];
				indArr[j + 1] = temp;
			}

	}

	return 0;
}


/* ���������� ������� �������� �� ����� ������ (sumContribution) */
int bubbleSortSum(dataBase *db, int* indArr)
{
	int temp2;
	for (int i = 0; i<N-1; i++)
	{
		for (int j = 0; j<N-1; j++)
			if (db[indArr[j]].sumContribution > db[indArr[j + 1]].sumContribution)   //���������� �������� �������, ����� ��������� ������
		 
			{
				// ������ �������� �������. �������� ������� db ���������� �� ������������, �� �� ������ �� ������� � ��������� �������
				temp2 = indArr[j];
				indArr[j] = indArr[j + 1];
				indArr[j + 1] = temp2;
			}

	}
	
	return 0;	
}


int main()
{		
	dataBase* db = new dataBase[N];  //�������� ������������� ������� db
	int* indArr = new int[N]; //��������� ������ ������������ indArr
	int* indArr2 = new int[N]; //��������� ������ ������������ indArr2

	/* ����� ������� ������ �� ����� */
	ReadBase(db, indArr, indArr2); 
	/* ����� �� ����� */
	output(db, indArr);  

	
	/* ����� ������� ���������� ��������� �� ����� */
	bubbleSortName(db, indArr); 	
	/* ����� �� ����� */
	output(db, indArr);  

	
	/* ����� ������� ���������� ��������� �� ����� ������ */
	bubbleSortSum(db, indArr2); 
	/* ����� �� ����� */
	output(db, indArr2);
	


	delete [] db;
	getch();
	return 0;
}

