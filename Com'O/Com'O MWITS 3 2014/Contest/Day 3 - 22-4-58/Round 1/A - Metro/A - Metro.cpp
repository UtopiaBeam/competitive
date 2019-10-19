#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
double dp[1005][1005];
int r,c,k,a[1005][1005];
int main(){
    scanf("%d %d %d",&c,&r,&k);
    while(k--){
        int x,y;
        scanf("%d %d",&y,&x);
        a[x][y]=1;
    }
    dp[0][0]=0;
    for(int i=0;i<=r;i++)
        dp[i][0]=100*i;
    for(int j=0;j<=c;j++)
        dp[0][j]=100*j;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+100;
            if(a[i][j])     dp[i][j]=min(dp[i][j],dp[i-1][j-1]+100*sqrt(2));
        }
    printf("%.0lf\n",dp[r][c]);
    return 0;
}
