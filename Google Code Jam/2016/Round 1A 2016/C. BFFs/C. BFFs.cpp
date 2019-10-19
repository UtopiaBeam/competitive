#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int g[1002][1002],n,v,t,mx[1002],d[1002];
int dfs(int u){
	mx[u]=1;
	for(int i=1;i<=n;i++)
		if(g[u][i] && !mx[i])
			mx[u]=max(mx[u],dfs(i)+1);
	return mx[u];
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		memset(g,0,sizeof(g));
		memset(mx,0,sizeof(mx));
		memset(d,0,sizeof(d));
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&v);
			if(!g[i][v]){
				d[i]++;		d[v]++;
			}
			g[i][v]=g[v][i]=1;
		}
		for(int i=1;i<=n;i++){
			if(d[i]==1 && !mx[i])
				dfs(i);
		}
		for(int i=1;i<=n;i++)
			if(!mx[i])
				dfs(i);
		for(int i=1;i<=n;i++)
			ans=max(ans,mx[i]);
		printf("Case #%d: %d\n",q,ans);
	}
	return 0;
}