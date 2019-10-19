#include<stdio.h>

int main()
{
    int i,j,n,width;
    scanf("%d",&n);

    width=2*n+1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=width;j++)
        {
            if(j<=n-i||j>=width+i+1-n)
                printf("-");
            else
                printf("*");
        }
        printf("\n");
        for(j=1;j<=width;j++)
        {
            if(j>n-i && j<width+i+1-n)
                if(n%2==1)
                    if((i+j)%2==1)
                        printf("-");
                    else
                        printf("*");
                else
                    if((i+j)%2==1)
                        printf("*");
                    else
                        printf("-");
            else
                printf("-");
        }
        printf("\n");
    }
    for(i=1;i<=width;i++)
    {
        printf("*");
    }
    return 0;
}
