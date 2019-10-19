//Floyd-Warshall
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[70][70],m,s,e;
int main(){
    scanf("%d %d %d",&m,&s,&e);
    for(int i=1;i<=60;i++)
        for(int j=1;j<=60;j++)
            if(i==j)    dp[i][j]=0;
            else        dp[i][j]=1<<20;
    while(m--){
        int str,end;
        scanf("%d %d",&str,&end);
        dp[str][end]=dp[end][str]=1;
    }
    //Floyd-Warshall
    for(int k=1;k<=60;k++)
        for(int i=1;i<=60;i++)
            for(int j=1;j<=60;j++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    printf("%d\n",dp[s][e]);
    return 0;
}
