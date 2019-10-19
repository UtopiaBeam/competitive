#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int q,n,m,u,v,sz;
int g[402][402],chk[402],t[2];
int dp[2][402];
vector<int> cnt[2];
bool bpt=true;
void dfs(int x,int cr){
	if(chk[x]>=0)	   return ;
	if(!bpt)			return ;
	chk[x]=cr;
	t[cr]++;
	for(int i=1;i<=n;i++){
		if(g[x][i]){
			if(chk[i]<0)
				dfs(i,1-cr);
			if(chk[i]==cr){
				bpt=false;
				return ;
			}
		}
	}
}
int main(){
	scanf("%d",&q);
	while(q--){
		memset(g,1,sizeof(g));
		memset(dp,0,sizeof(dp));
		cnt[0].clear();
		cnt[1].clear();
		scanf("%d %d",&n,&m);
		while(m--){
			scanf("%d %d",&u,&v);
			g[u][v]=g[v][u]=0;
		}
		for(int i=1;i<=n;i++){
			g[i][i]=0;
			chk[i]=-1;
		}
		bpt=true;
		for(int i=1;i<=n && bpt;i++){
			if(chk[i]<0){
				t[0]=t[1]=0;
				dfs(i,0);
				if(!bpt)	break;
				cnt[0].push_back(t[0]);
				cnt[1].push_back(t[1]);
			}
		}
		if(!bpt){
			printf("-1\n");
			continue;
		}
		dp[1][0]=1;
		int sz=cnt[0].size();
		for(int i=0;i<sz;i++){
            for(int j=1;j<=n;j++)
                dp[i&1][j]=0;
			for(int j=n;j>=cnt[0][i];j--)
				dp[i&1][j]|=dp[!(i&1)][j-cnt[0][i]];
			for(int j=n;j>=cnt[1][i];j--)
				dp[i&1][j]|=dp[!(i&1)][j-cnt[1][i]];
		}
		for(int i=n/2;i>=0;i--){
			if(dp[!(sz&1)][i]){
				printf("%d\n",n-2*i);
				break;
			}
		}
	}
	return 0;
}
