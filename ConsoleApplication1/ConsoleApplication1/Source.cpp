#include<stdio.h>
#include<cmath>
//float a, b, c;
int main()
{
	float a, b, c, d, x, x1, x2; 
	a = 0;
	b = 0;
	c = 0;
	x = 0;
	x1 = 0;
	x2 = 0;
	d = 0;

	printf("vvedite index a=");
	scanf_s("%f", a);
	printf("vvedite index b=");
	scanf_s("%f", b);
	printf("vvedite index a=");
	scanf_s("%f", c);
	d = b*b - 4 * a*c;

	if (d>0)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
	}

	if (d == 0)
		x = -b / (2 * a);

	if (d < 0)
		printf("korney net");

	printf("x1=");
	printf("%-+15.5f\n", x1);
	printf("x2=");
	printf("%-+15.5f\n", x2);
	printf("x=");
	printf("%-+15.5f\n", x);

}