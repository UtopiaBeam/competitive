#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char a[250];
    int len,i,cnt=0;
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        if(isupper(a[i]))
        {
            if((i+cnt)%4==1)  cnt+=3;
            if((i+cnt)%4==2)  cnt+=2;
            if((i+cnt)%4==3)  cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
