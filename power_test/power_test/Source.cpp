#include<stdio.h>
#include<cmath>
#include<cstdlib>
//#include <stdafx.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>

int main()
{
	int *m, i, j, t, n;
	long double s = 0;
	n = 50000;

	m = (int*)malloc(sizeof(int)*n); //инициализация основого массива
	if (m == nullptr) //проверка
		return 0;
	srand(time(0));
	for (i = 0; i < n; i++)
	{
		
		*(m + i) = rand() % 187459356 + 134;
		//printf("%d\t", *(m + i));
	}

	

	for (i = n - 1; i > 1; i--)
	{
		for (j = 0; j < i; j++)
			if (*(m + (j + 1)) < *(m + j)) //если последующий элемент меньше предыдущего, то производится обмен элементами с последующим значением в массиве
			{
			t = *(m + (j + 1));
			*(m + (j + 1)) = *(m + j);
			*(m + j) = t;
			s = s + 1;
			//system("cls");
			//printf("%d", s);
			}
	}
	for (i = 0; i < n; i++)
		printf("%d\t", *(m + i));
	printf("\n");
	printf("%d", s);
}