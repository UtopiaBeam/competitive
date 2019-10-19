#include<stdio.h>
int a[550][550],n;
int main(){
    int i,j,k,l,now,sum,max=-10000000;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            scanf("%d",&now);
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+now;
        }
    for(k=1;k<=n;k++)
        for(l=1;l<=n;l++)
            for(i=0;i<=n-k;i++)
                for(j=0;j<=n-k;j++){
                    sum=a[i+l][j+k]-a[i+l][j]-a[i][j+k]+a[i][j];
                    if(max<sum)   max=sum;
                }
    printf("%d\n",max);
    return 0;
}
