#include<stdio.h>
#include<math.h>
#include<cstdlib>


long double arr[14], brr[14], err[14], drr[14], frr[14], grr[14], mrr[14]; //���������� ���������� ��� ����������


int main()
{
	int a, b, p; //����� ��� �����
	int i; //������� �������
	i = 0;
	//float mrr[13]; //������ ������ ��� ����������

	a = rand() % 11 + 1; //��������� ��������� ������
	b = rand() % 11 + 1;
	p = rand() % 30 + 1;

	printf("Key A");
	printf("%d\n", a);
	printf("Key B");
	printf("%d\n", b);
	//printf("%d", p);
	printf("\n");

	for (i = 0; i <= 13; i++)
	{
		mrr[i] = rand() % 97 + 1; //��������� ������� ��������� ������� � ��������� 1-74
	}
	printf("Data array");
	for (i = 0; i <= 13; i++) //�������� �����
	{
		printf("%f\t", mrr[i]);
	}

	printf("\n");

	for (i = 0; i <= 13; i++)
	{
		arr[i] = pow(mrr[i], a); //���������� �� ��������� ������
		brr[i] = pow(mrr[i], b);
	}

	printf("\n");
	printf("Data array kript by A and B");
	printf("\n");

	for (i = 0; i <= 13; i++)
	{
		printf("%f\t", arr[i]);
		printf("%f\t", brr[i]);
	}
	printf("\n");

	for (i = 0; i <= 13; i++)
	{
		err[i] = pow(arr[i], b); //������ ���������� �� ��� �����
		drr[i] = pow(brr[i], a);
	}
	printf("\n");
	printf("Data array kript by AB and BA");
	printf("\n");
	for (i = 0; i <= 13; i++)
	{
		printf("%f\t", err[i]);
		printf("%f\t", drr[i]);
	}
	printf("\n");

	for (i = 0; i <= 13; i++)
	{
		frr[i] = log10(err[i]) / log10(arr[i]); //����������
		grr[i] = log10(drr[i]) / log10(brr[i]);
	}
	printf("\n");

	printf("Encrepted B");
	printf("\n");
	for (i = 0; i <= 13; i++)
	{
		printf("%lf\t", frr[i]);
	
	}

	printf("\n");
	printf("Encrepted A");
	printf("\n");
	for (i = 0; i <= 13; i++)
	{
		printf("%lf\t", grr[i]);
	}
	printf("\n");
}
