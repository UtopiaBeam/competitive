#include<stdio.h>
int a[1010][1010],x,y;
int main(){
    int k,i,j;
    scanf("%d %d %d",&x,&y,&k);
    for(i=0;i<=x;i++)
        for(j=0;j<=y;j++)
            a[i][j]=1;
    while(k--){
        scanf("%d %d",&i,&j);
        a[i][j]=0;
    }
    for(i=1;i<=x;i++){
        for(j=1;j<=y;j++){
            if(a[i][j]!=0)
                a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    printf("%d\n",a[x][y]%1000000);
    return 0;
}
