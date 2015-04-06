#include<stdio.h>
#include<iostream>
#include <stdlib.h>     
#include <time.h> 
#include <conio.h>

int a[4][4], p[4][4];

int main()
{
	int i = 0, j = 0, t = 0, x, y, st = 0, v = 0, input, f = -1, i1, j1, f1, i2=-1;
	x = 4;
	y = 4;

	srand(time(NULL));
	
	
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
		a[i][j] = 0;
		}

	i = rand() % 3;
	j = rand() % 3;

	a[i][j] = 2;
	
	while (t == i && v == j)
	{
		t = rand() % 3;
		v = rand() % 3;
	}
	
	a[t][v]=2;
	
	i = 0;
	j = 0;

	while (true)
	{
		system("cls");

		for (i = 0; i < x; i++)
		{
			printf("\n");
			printf("\n");
			for (j = 0; j < y; j++)
				printf("%6d", a[i][j]);
		}
		
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				p[i][j] = a[i][j];

		i2 = -1;
		i = 0;
		j = 0;

		input = getch();

		switch (input)
		{
		case 72: //стрелка вверх
		{
			for (j = 0; j < 3; j++)
			{
				for (i = 3; i > 0; i--)
				{
					if (a[i][j] != 0)
					{
						f1 = i - 1;
						for (i1 = f1; i1 >= 0; i1--)
						{
							if (a[i1][j] != 0)
							{
								if (i2 == -1)
									i2 = i1;
								if (i2 != -1)
									break;
							}
						}

						if (i2 == -1)
						{
							while ((a[i - 1][j] == 0) || (i != 0))
							{
								a[i - 1][j] = a[i][j];
								a[i][j] = 0;
								i = i - 1;
								if (i == 0)
									break;
							}
							
						}
						else
						{
							if ((a[i2][j] == a[i][j]) && (i2 + 1== i))
							{
								a[i2][j] = a[i2][j] + a[i][j];
								a[i][j] = 0;
							}
							else
							{
								a[i2 + 1][j] = a[i][j];
								a[i][j] = 0;
							}
						}
					}
					else
						for (st = 3; st > 1; st--)
							break;
				}
			}

			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (p[i][j] != a[i][j])
						f = 0;
				}
			}

			if (f == 0)
			{
				i = rand() % 3;
				j = rand() % 3;
				while (a[i][j] != 0)
				{
					i = rand() % 3;
					j = rand() % 3;
				}
				a[i][j] = 2;
			}

			break;
		}
		
		case 80: //стрелка вниз
		{

		}
		case 75:	//стрелка влево
		{

		}
		case 77: //стрелка вправо
		{

		}
		}


		printf("\n");
		//scanf("%d", &st);
	}
}