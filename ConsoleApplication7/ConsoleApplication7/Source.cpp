#include <stdio.h>
#include <stdlib.h>




int ff(char *str, int i)
{
	int dl;
	if (*(str + i) == '\0')
		return 0;
	if (*(str+i)==' ')

}



int main()
{
	char *str;
	int n;
	//scanf("%d", &n);
	n = 15;

	fflush(stdin);
	str = (char*)malloc(sizeof(char)*n);
	gets(str);
	//*str = "la ffa bar alta";

	int max = ff(str, 0);
	printf("%d", max);
	puts(str);
	getchar();
	return 0;
}