#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int r[1002],w[1002],v[1002],dp[2][1002];
int n,m,W,x,y,mx=0,sz=0;
vector<int> g[1002];
int fr(int x){
    if(x!=r[x])     r[x]=fr(r[x]);
    return r[x];
}
int main(){
    scanf("%d %d %d",&n,&m,&W);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i);
    for(int i=1;i<=n;i++)
        scanf("%d",v+i);
    for(int i=1;i<=n;i++)
        r[i]=i;
    while(m--){
        scanf("%d %d",&x,&y);
        int rx=fr(x),ry=fr(y);
        if(rx==ry)      continue;
        r[max(rx,ry)]=min(rx,ry);
    }
    for(int i=1;i<=n;i++){
        int ri=fr(i);
        g[ri].push_back(i);
        sz=max(sz,ri);
    }
    for(int i=1;i<=sz;i++){
        int wsum=0,vsum=0;
        for(int x:g[i]){
            wsum+=w[x];     vsum+=v[x];
            for(int j=W;j>=w[x];j--)
                dp[1][j]=max(dp[1][j],dp[0][j-w[x]]+v[x]);
        }
        for(int j=W;j>=wsum;j--)
            dp[1][j]=max(dp[1][j],dp[0][j-wsum]+vsum);
        for(int j=0;j<=W;j++)
            dp[0][j]=dp[1][j];
    }
    for(int i=0;i<=W;i++)
        mx=max(mx,dp[0][i]);
    printf("%d\n",mx);
    return 0;
}
