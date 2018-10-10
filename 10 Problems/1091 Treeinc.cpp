#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> adj[300005];
int dp[300005];
int main(){
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        dp[i]=1;
    for(int i=1;i<n;i++){
        int str,end;
        scanf("%d %d",&str,&end);
        if(str<end)     adj[str].push_back(end);
        else    adj[end].push_back(str);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++)
            dp[adj[i][j]]=max(dp[adj[i][j]],dp[i]+1);
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}
