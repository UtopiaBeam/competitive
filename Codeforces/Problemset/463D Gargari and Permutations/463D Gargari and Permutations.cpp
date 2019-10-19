#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> g[1002],tp;
queue<int> q;
int a[5][1002],n,m,t,d[1002],dp[1002],mx=0;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&t);
            a[i][t]=j;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            bool chk=true;
            for(int k=0;k<m && chk;k++)
                chk=a[k][i]<a[k][j];
            if(chk)     g[i].push_back(j),d[j]++;
        }
    for(int i=1;i<=n;i++)
        if(!d[i]){
            dp[i]=1;
            q.push(i);
        }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        tp.push_back(u);
        for(int j=0;j<g[u].size();j++){
            int v=g[u][j];
            d[v]--;
            if(!d[v])   q.push(v);
        }
    }
    for(int i=0;i<tp.size();i++){
        int u=tp[i];
        for(int j=0;j<g[u].size();j++){
            int v=g[u][j];
            dp[v]=max(dp[v],dp[u]+1);
        }
    }
    for(int i=1;i<=n;i++)
        mx=max(mx,dp[i]);
    printf("%d\n",mx);
    return 0;
}
