#include<stdio.h>
int a[1010][1010],r,c;
int main(){
    int k,i,j,num;
    scanf("%d %d %d",&r,&c,&k);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++){
            scanf("%d",&num);
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+num;
        }

}
