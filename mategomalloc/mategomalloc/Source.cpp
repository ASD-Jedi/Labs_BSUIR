#include<stdio.h>
#include <iostream>


int main()
{
	int n, i = 0, *m, *r, t = 0, j = 0, *s, *f, y = 0; //������������� ���������� � ����������
	
	scanf("%d", &n); //���� ������� �������

	m = (int*)malloc(sizeof(int)*n); //������������� �������� �������
	if (m == nullptr) //��������
		return 0;

	r = (int*)malloc(sizeof(int)*n); //������������� ������� ��� ���������� �� �����������
	if (r == nullptr) //��������
		return 0;

	s = (int*)malloc(sizeof(int)*n); //������������� ������� ��� ���������� ������/������ ����
	if (s == nullptr) //��������
		return 0;

	f = (int*)malloc(sizeof(int)*n); //������������� ������� ��� ���������� �� ���������� ������
	if (f == nullptr) //��������
		return 0;

	for (i = 0; i < n; i++)
		scanf("%d", m + i); //���� ��������� �������

	printf("\n");

	for (i = 0; i < n; i++) //����� ������� �������
		printf("%d\t", *(m + i));

	//���������� �� �����������
	for (i = 0; i < n; i++) //����������� �������� ��������� ������� ������� ��� ���������
		*(r + i) = *(m + i);

	for (i = n - 1; i > 1 ; i--)
	{
		for (j = 0; j < i; j++)
		if (*(r + (j + 1)) < *(r + j)) //���� ����������� ������� ������ �����������, �� ������������ ����� ���������� � ����������� ��������� � �������
		{
			t = *(r + (j + 1));
			*(r + (j + 1)) = *(r + j);
			*(r + j) = t;
		}
	}

	printf("\n");
	for (i = 0; i < n; i++) //����� ����������� �������
		printf("%d\t", *(r + i));


//����� ���������� ������/������ ����

	for (i = 0; i < n; i++) //����������� �������� ��������� ������� ������� ��� ���������
		*(s + i) = *(m + i); 
	printf("\n");

	t = 0; //��������� ������� ����������


	for (i = n - 1; i > 1; i--) 
	{
		for (j = 0; j < i; j++)
		{
			if (*(s + j)>0) //���� ������� ������ ����, �� �� ���������� ������
			{
				t = *(s + j);
				*(s + j) = *(s + (j + 1));
				*(s + (j + 1)) = t;
			}
		}
	}

	t = 0; //��������� ������� ����������

	
	//��� ��� ���� �� ���� ��������� ���������� ������, �� ������ ������ ����� �������������� � �������������� �������, ����������� ��������� ����
	

	for (i = n - 1; i > 1; i--) 
	{
		for (j = 0; j < i; j++)
		{
			if (*(s + j) == 0 && *(s + (j + 1)) < 0) //���� ������� ����� ���� � ��������� ������� ������� �� ��� �������������, �� ���� ��������� �� ��� �����
			{
				t = *(s + j);
				*(s + j) = *(s + (j + 1));
				*(s + (j + 1)) = t;
			}
		}
	}

	for (i = 0; i < n; i++) //����� ����������� �������
		printf("%d\t", *(s + i));


	printf("\n");
	t = 0; //��������� ����������

	//���������� �� ���������� ������
	for (i = 0; i < n; i++) //����������� �������� ��������� ������� ������� ��� ���������
		*(f + i) = *(m + i);

	for (i = n - 1; i > 1; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (*(f + j) > 0) //�� ��������, ���� ������� ������ ����, �� �� ������ ���� ��������� ������
			{
				for (y = j; y < i; y++) //���� �������, �������� ��� ������
				{
					if (*(f + y) != 0) // ���� ������� �� ����� ����, �� ��� ����� � ��������� ���� ���������
					{
						t = *(f + j);
						*(f + j) = *(f + y);
						*(f + y) = t;
					}
				}
			}
		}
	}




	for (i = 0; i < n; i++) //����� ����������� �������
		printf("%d\t", *(f + i));
}