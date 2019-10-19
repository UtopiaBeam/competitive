#include<stdio.h>
int a[15][10];
int main(){
    int i,j;
    for(i=0;i<=10;i++)
        a[i][0]=1;
    for(i=1;i<=10;i++)
        for(j=1;j<=i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
   printf("%d\n",a[10][5]);
    return 0;
}
