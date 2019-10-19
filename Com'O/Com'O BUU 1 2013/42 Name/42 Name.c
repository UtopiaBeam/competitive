#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,q,len,cnt=1;
    char a[1020];
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf(" %s",a);
        len=strlen(a);
        for(j=0;j<len;j++)
        {
            if(a[j]==a[j+1])    cnt++;
            else
            {
                printf("%d%c",cnt,a[j]);
                cnt=1;
            }
        }
        printf("\n");
    }
    return 0;
}
