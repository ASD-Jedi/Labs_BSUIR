#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <locale>
#include <windows.h>

#define n 5
#define mrk 3
using namespace std;


struct data
{
	char fam[30];
	int oc[mrk];
	float step;
};

void rewrite(struct data *obr, int l)
{
	system("cls");
	for (int i = 0; i < l; i++)
	{
		cout << (*(obr + i)).fam << "	";
		for (int j = 0; j < mrk; j++)
		{
			cout << "оценка " << (*(obr + i)).oc[j] << "		";
		}
		cout << endl;
	}

}

void update(struct data *obr, int l)
{
	system("cls");
	for (int i = 0; i < l; i++)
	{
		cout << (*(obr + i)).fam << "	";
		for (int j = 0; j < mrk; j++)
		{
			cout << "оценка " << (*(obr + i)).oc[j] << "		";
		}
		cout << (*(obr + i)).step << endl;
	}

}


int main()
{
	setlocale(LC_ALL, "Russian");
	struct data *obr;
	obr = (data*)malloc(sizeof(data)*n);

	for (int i = 0; i < n; i++)
	{
		cout << "введите имя студента №" << i << endl;
		cin >> (*(obr + i)).fam;
		rewrite(obr, i);
		
		for (int j = 0; j < mrk; j++)
		{
			cout << "введите оценку №" << i << "	";
			cin >> (*(obr + i)).oc[j];
			rewrite(obr, i);
		}

	}
	rewrite(obr, n);

	for (int i = 0; i < n; i++)
	{
		float t = 0;
		for (int j = 0; j < mrk; j++)
		{
			t = t + (*(obr + i)).oc[j];
		}
		t = t / mrk;

		if (t < 5)
			(*(obr + i)).step = 0;
		if (t>5 && t < 7)
			(*(obr + i)).step = 576000;
		if (t >= 7 && t < 9)
			(*(obr + i)).step = 890000;
		if (t >= 9)
			(*(obr + i)).step = 1100000;
	}

	update(obr, n);


	




	system("PAUSE");
	return 0;
}