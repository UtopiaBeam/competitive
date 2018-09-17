#include<stdio.h>

int main()
{
    int m,n,i,j,A[102][102],B[102][102];
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&A[i][j]);
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&B[i][j]);
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",A[i][j]+B[i][j]);
            printf("\n");
    }
    return 0;
}
