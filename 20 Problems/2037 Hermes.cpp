#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,x[20005]={1000},y[20005]={1000},dp[2][2][2005],now=0,nx=1;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x[i],&y[i]);
        x[i]+=1000,y[i]+=1000;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2001;j++){
            dp[nx][0][j]=min(dp[now][0][j]+abs(x[i+1]-x[i]),dp[now][1][x[i]]+abs(y[i+1]-j));
            dp[nx][1][j]=min(dp[now][1][j]+abs(y[i+1]-y[i]),dp[now][0][y[i]]+abs(x[i+1]-j));
        }
        swap(now,nx);
    }
    printf("%d\n",dp[now][0][1000]);
    return 0;
}
