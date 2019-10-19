#include<stdio.h>

int main()
{
    int m,n,i,j,a[20][20];
    scanf("%d %d",&n,&m);
    for(j=0;j<n;j++)
    {
         for(i=0;i<m;i++){
            scanf("%d",&a[i][j]);
         }

    }
    for(j=0;j<n;j++)
    {
         for(i=0;i<m;i++){
            printf("%d ",a[i][j]);
         }

    }
    printf("\n");
    for(j=n-1;j>=0;j--)
    {
         for(i=m-1;i>=0;i--){
            printf("%d ",a[i][j]);
         }

    }
    printf("\n");
    for(i=0;i<m;i++)
    {
         for(j=0;j<n;j++){
            printf("%d ",a[i][j]);
         }

    }
    printf("\n");
    for(i=m-1;i>=0;i--)
    {
         for(j=n-1;j>=0;j--){
            printf("%d ",a[i][j]);
         }

    }
    return 0;
}
