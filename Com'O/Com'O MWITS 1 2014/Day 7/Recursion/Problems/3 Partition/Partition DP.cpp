#include<stdio.h>
long long mic[1010][1010];
int main(){
    int i,j,k,l,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        mic[i][1]=mic[i][i]=mic[i][i-1]=1;
    for(i=4;i<=n;i++)
        for(j=2;j<i-1;j++)
            for(k=1;k<=j;k++){
                mic[i][j]+=mic[i-j][k];
            }
    for(i=1;i<=n;i++)
        for(j=1;j<i;j++)
            mic[i][j+1]+=mic[i][j];
    printf("%lld\n",mic[n][n]);
    return 0;
}
