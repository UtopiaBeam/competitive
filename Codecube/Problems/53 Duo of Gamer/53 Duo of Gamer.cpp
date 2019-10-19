#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,A,B,k,dp[2][105][105][25],x[35],y[35],v[35];
int main(){
    scanf("%d",&q);
    while(q--){
        int ans=-1,next=1,now=0;
        scanf("%d %d %d %d",&n,&A,&B,&k);
        memset(dp,0,sizeof(dp));
        dp[0][A][B][k]=0;
        for(int i=0;i<n;i++)
            scanf("%d %d %d",&x[i],&y[i],&v[i]);
        for(int i=0;i<n;i++){
            for(int a=1;a<=A;a++)
                for(int b=1;b<=B;b++)
                    for(int j=0;j<=2*k;j++){
                        dp[next][a][b][j]=max(dp[now][a][b][j],dp[next][a][b][j]);
                        if(a>x[i] && j>0)   dp[next][a-x[i]][b][j-1]=max(dp[next][a-x[i]][b][j-1],dp[now][a][b][j]+v[i]);
                        if(b>y[i] && j<2*k) dp[next][a][b-y[i]][j+1]=max(dp[next][a][b-y[i]][j+1],dp[now][a][b][j]+v[i]);
                        dp[now][a][b][j]=0;
                    }
            now++,next++,now%=2,next%=2;
        }
        for(int a=1;a<=A;a++)
            for(int b=1;b<=B;b++)
                for(int j=0;j<=2*k;j++)
                    ans=max(ans,dp[now][a][b][j]);
        printf("%d\n",ans);
    }
    return 0;
}
