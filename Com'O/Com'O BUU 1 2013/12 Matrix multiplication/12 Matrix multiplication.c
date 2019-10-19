#include<stdio.h>

int main()
{
    int m1,n1,m2,n2,i,j,k,AxB;
    scanf("%d %d %d %d",&m1,&n1,&m2,&n2);
    if(n1!=m2)
    {
        printf("Can't Multiply.");
        return 0;
    }

    int A[m1][n1],B[m2][n2];
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }

    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            for(k=0,AxB=0;k<m2;k++)
            {
                AxB+=A[i][k]*B[k][j];
            }
                printf("%d ",AxB);
        }
        printf("\n");
    }

    return 0;
}
