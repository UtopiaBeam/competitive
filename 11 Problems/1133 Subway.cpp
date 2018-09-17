#include<cstdio>
#include<vector>
#include<algorithm>
#define INF (int)1e9
using namespace std;
int n,m,x,y,dp[502][502];
vector<int> a[1000002];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<m;i++)
        for(int j=i+1;j<=m;j++)
            dp[i][j]=dp[j][i]=INF;
    for(int i=1;i<=m;i++){
        scanf("%d",&n);
        while(n--){
            scanf("%d",&x);
            for(int j=0;j<a[x].size();j++){
                dp[i][a[x][j]]=min(dp[i][a[x][j]],1);
                dp[a[x][j]][i]=min(dp[a[x][j]][i],1);
            }
            a[x].push_back(i);
        }
    }
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    scanf("%d",&n);
    while(n--){
        int mn=INF;
        scanf("%d %d",&x,&y);
        for(int i=0;i<a[x].size();i++)
            for(int j=0;j<a[y].size();j++){
                int u=a[x][i],v=a[y][j];
                mn=min(mn,dp[u][v]);
            }
        if(mn==INF)     printf("impossible\n");
        else    printf("%d\n",mn);
    }
    return 0;
}
