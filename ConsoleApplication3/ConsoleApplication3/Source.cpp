#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

int main()
{
	int *a, n, x, y, i, j, d = 0, f = 0;
	

	printf("vvedite razmer massiva\n");
	scanf("%d", &n);

	a = (int*)malloc(sizeof(int)*n); //��������� ������
	if (!a) //�������� ���������
		return 0;

	printf("vvedite elementy massiva\n");
	for (i = 0; i<n; i++) //���� ��������� �������
		scanf("%d", a + i);

	for (i = n; i>0; i--) //���������� ������� ���������
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

	//���� ������������ �������
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

	

	int *v = (int*)malloc(sizeof(int)*x*y); //��������� ������ ��� ������� ���������� �������

	for (i = 0; i<x; i++)
	{
		if (f != 0) //���� ������ ������, �� ������������ ��������� ������ ��� � �������� �������
		{
			for (j = y; j>0; j--)
			{
				*(v + i*x + j) = *(a + d);
				f = 0;
				d++;
			}
		}
		else //���� �������� ������, �� ������������ ��� �� ������� � ���������� ��������
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
			printf("%3d", *(v + i*y + j)); //����� �������
		}
	}
	printf("\n");
}