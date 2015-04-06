#include <stdio.h>

//int arr[10] = { 9, 8, 3, 11, 17, 24, 27, 8, 6, 9 }; //отладочный массив
int arr[10]; //задание массива
int main()
{
	int f1 = -1, f2 = -1, fmax = 0, fmin = 0, i, d = 0, t = 0, j, n = 0, l = 0, a = 0; //инициализация переменных
	

	for (i = 0; i <= 9; i++)  //ввод элементов массива
		scanf_s("%d", &arr[i]);
	
	for (i = 0; i <= 9; i++) 
		printf("%d\t", arr[i]);
	
	printf("\n");

	for (i = 1; i <= 9; i++) 
	{
		if (arr[i] > arr[i - 1])
		{
			if (f1 == -1)
				f1 = i-1; 
			else
				f2 = i; 
		}
		else
		{
			if (f2 > -1) 
				break; 
		}
	}

	d = (f2 - f1) / 2;
	l = f2;
	for (i = f1; i <= f1 + d; i++)
	{
		t = arr[i];
		arr[i] = arr[l];
		arr[l] = t;
		l = l - 1;
	}

	for (i = 0; i <= 9; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	
	l = f1;
	for (i = 9; i > f2; i--)
	{
		t = arr[i];
		arr[i] = arr[l];
		arr[l] = t;
		l = l + 1;
	}

	for (i = 0; i <= 9; i++)
		printf("%d\t", arr[i]);
	printf("\n");


	i = 9;
	l = f2 - f1 + 1;
	while (i >= l)
	{
		arr[i] = 0;
		i--;
	}

	for (i = 0; i <= 9; i++)
		printf("%d\t", arr[i]);
	printf("\n");

}