#include<cstdio>
#include<algorithm>
using namespace std;
int w[605][605],dp[605],n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*n;j++)
            scanf("%d",&w[i][j]);
    }
    for(int i=2;i<2*n;i++)
        dp[i]=1<<20;
    //Shortest path from 2*n to 2
    for(int i=2*n;i>1;i--){
        for(int j=i-1;j>1;j--)
            dp[j]=min(dp[j],dp[i]+w[i][j]);
    }
    printf("%d\n",dp[2]);
    return 0;
}
