#include <QtCore/QCoreApplication>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j, n, beg, en, begstr;
    char *str;
    char ff;
    scanf("%d", &n);

    str=(char*)malloc(sizeof(char)*n);
    if(!str)
        return 0;

    fflush(stdin);
    gets(str);

    for (i=0; i<n; i++)
        if(*(str+i)!=' ')
        {
            ff=*(str+i);
            if(ff)
                break;
            begstr=i;
        }
    i=begstr;

    while(*(str+i))
    {
        while(*(str+i)==' ')
            i++;

        if(*(str+i)==ff&&*(str+i-1)==' ')
        {
            beg=i;
            while(*(str+i)!=' ')
            {
                en=i;
                i++;
            }

        }
        i++;
    }



    for(i=beg; i<en; i++)
        printf("%c", *(str+i));
return 0;
getchar();
}
