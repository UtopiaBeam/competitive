#include<stdio.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);

    for(i=1;i<2*n;i++)
    {
        for(j=1;j<=4*n-3;j++)
        {
            if(j<i)
            {
                if(j%2)
                    printf("#");
                else
                    printf(".");
            }
            else if(i+j>4*n-2)
            {
                if(j%2)
                    printf("#");
                else
                    printf(".");
            }
            else if(i%2)
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
    for(i=2*n-2;i>0;i--)
    {
        for(j=1;j<=4*n-3;j++)
        {
            if(j<i)
            {
                if(j%2)
                    printf("#");
                else
                    printf(".");
            }
            else if(i+j>4*n-2)
            {
                if(j%2)
                    printf("#");
                else
                    printf(".");
            }
            else if(i%2)
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }

    return 0;
}
