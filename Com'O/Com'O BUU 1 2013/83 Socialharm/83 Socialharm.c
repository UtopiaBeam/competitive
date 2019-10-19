#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char a[200];
    int len,i,cnt=0;
    gets(a);

    len=strlen(a);
    for(i=0;i<len;i++)
        a[i]=tolower(a[i]);

    for(i=0;i<len;i++)
    {
        if(!strncmp(&a[i],"mukissocialharm",15))
        {
            cnt++;
        }
    }
    printf("%d\n",cnt);

    return 0;
}
