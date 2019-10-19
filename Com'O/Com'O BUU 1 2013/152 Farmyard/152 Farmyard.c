#include<stdio.h>
long long farm[1205][1205];
int main(){
    long long total,max=0;
    int i,j,n,here;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&here);
            farm[i][j]=farm[i-1][j]+farm[i][j-1]-farm[i-1][j-1]+here;
        }
    }
    for(i=0;i<=n-9;i++){
        for(j=0;j<=n-9;j++){
            total=farm[i+9][j+9]-farm[i+9][j]-farm[i][j+9]+farm[i][j];
            if(max<total)   max=total;
        }
    }
    printf("%lld\n",max);
    return 0;
}
