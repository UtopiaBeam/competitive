#include<stdio.h>

int main()
{
    int n,i,j;
    char ch;
    scanf("%c",&ch);
    scanf("%d",&n);

    for(i=1;i<=n/2;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j<=i||j>=n+1-i)
                printf("%c",ch);
            else
                printf(".");
        }
        printf("\n");
    }
    for(i=n/2+1;i<n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j>i||j<n+1-i)
                printf("%c",ch);
            else
                printf(".");
        }
        printf("\n");
    }
    return 0;
}
