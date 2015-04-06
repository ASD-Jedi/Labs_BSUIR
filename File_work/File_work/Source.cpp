#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <locale.h>
#include <io.h>

int main()
{
	FILE *ftl;
	int a[5] = { 5, 6, 9, 1, 4 };
	
	if (!(ftl = fopen("atr", "w+"))){
		puts ("error");
		return 0;
	}


	for (int i = 0; i<sizeof(a) / sizeof(int); i++)
		fprintf(ftl, "%2d", a[i]);

	rewind(ftl);

	while (!feof(ftl)){
		char a=fgetc(ftl);
		printf("%c", a);
	}
	rewind(ftl);
	

	//MAX BLOCK________________
	fpos_t pos, maxpos;
	int fl = -1, t, max;
	while (!feof(ftl)){
		pos = ftell(ftl);
		fscanf(ftl, "%d", &t);
		if (fl == -1){
			max = t;
			maxpos = pos;
			fl = 1;
		}
		else {
			if (max < t){
				maxpos = pos+2;
				max = t;
			}
		}
	}
	//___________________________

	printf("\n");
	printf("%d\n", max);
	printf("%ld\n", maxpos);
	rewind(ftl);
	fseek(ftl, maxpos, 0);
	char tt;
	tt = getc(ftl);
	printf("%c", tt);
	system("PAUSE");
	fclose(ftl);
	return 0;
}