#include <stdio.h>
#include <stdlib.h>

void massout(int *b, int k)
{
	int i;
	printf("\n");
	for (i = 0; i < k; i++)
		printf("%3d", *(b + i));
	printf("\n");
}

int main()
{
	int i, j, n, f1=-1, f2=-1, t, v;
	int *m;

	scanf_s("%d", &n);

	m = (int*)malloc(sizeof(int)*n);
	if (!m)
		return 0;

	for (i = 0; i < n; i++)
		scanf_s("%d", m + i);
	
	massout(m, n);

	for (i = 0; i < n; i++)
	{
		if (*(m + i) < *(m + i + 1))
			if (f1 == -1)
				f1 = i;
		if ((*(m + i) > *(m + i + 1)) && (f1 != -1) && (f1 < i))
			if (f2 == -1)
				f2 = i;
	}
	

	printf("%d\n", f1);
	printf("%d\n", f2);

	printf("\n");

	for (i = f1; i <= f2; i++)
		printf("%3d", *(m + i));

	i = f1;
	j = f2;
	v = f2 - f1;
	int ch = 0;
	while (ch<(v/2))
	{
		t = *(m + i);
		*(m + i) = *(m + j);
		*(m + j) = t;
		i++;
		j--;
		ch++;
	}

	massout(m, n);

	
	j = f1-1;
	for (i = f2; i < n; i++)
	{
		t = *(m + i);
		*(m + i) = *(m + j);
		*(m + j) = t;
		j++;
	}

	massout(m, n);
	ch = 0;
	i = n-1;
	while (ch <= v)
	{
		*(m + i) = 0;
		ch++;
		i--;
	}
	massout(m, n);

}
