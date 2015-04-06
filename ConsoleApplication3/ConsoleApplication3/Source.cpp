#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

int main()
{
	int *a, n, x, y, i, j, d = 0, f = 0;
	

	printf("vvedite razmer massiva\n");
	scanf("%d", &n);

	a = (int*)malloc(sizeof(int)*n); //выделение памяти
	if (!a) //проверка выделения
		return 0;

	printf("vvedite elementy massiva\n");
	for (i = 0; i<n; i++) //ввод элементов массива
		scanf("%d", a + i);

	for (i = n; i>0; i--) //сортировка массива пузырьком
	{
		for (j = 0; j<i; j++)
		{
			if (*(a + j)<*(a + j + 1))
			{
				int t = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = t;
			}
		}
	}

	//ввод размерностей матрицы
	printf("vvedite razmer matric'y");
	printf("\n");
	printf("vvedite x");
	printf("\n");
	scanf("%d", &x);
	printf("vvedite y");
	printf("\n");
	scanf("%d", &y);

	for (i = 0; i<n; i++)
		printf("%3d", *(a + i));
	printf("\n");

	

	int *v = (int*)malloc(sizeof(int)*x*y); //выделение памяти для матрицы сортировка змейкой

	for (i = 0; i<x; i++)
	{
		if (f != 0) //если строка чётная, то присваивание элементов строки идёт в обратном порядке
		{
			for (j = y; j>0; j--)
			{
				*(v + i*x + j) = *(a + d);
				f = 0;
				d++;
			}
		}
		else //если нечётная строка, то присваивание идёт от первого к последнему элементу
		{
			for (j = 0; j<y; j++)
			{
				*(v + i*y + j) = *(a + d);
				f = 1;
				d++;
			}
		}
	}

	for (i = 0; i<x; i++)
	{
		printf("\n");
		for (j = 0; j<y; j++)
		{
			printf("%3d", *(v + i*y + j)); //вывод массива
		}
	}
	printf("\n");
}