#include<stdio.h>
#include<string.h>

int main()
{
    char a[1200];
    int n,i,j,len;
    scanf(" %s",a);
    scanf("%d",&n);
    len=strlen(a);
    for(i=0;i<len;i+=n)
        for(j=n-1;j>=0;j--)
            if(i+j<len) printf("%c",a[i+j]);
    return 0;
}
