#include<stdio.h>

int main()
{
    int n,i,j;
    char a[2000],b[2000];
    scanf("%d %s %s",&n,a,b);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(i%2)
                a[j]|=b[i];
            else
                a[j]&=b[i];
        }
    printf("%s\n",a);

    return 0;
}
