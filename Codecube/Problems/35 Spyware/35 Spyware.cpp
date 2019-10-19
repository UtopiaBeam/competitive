#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define L long long
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,m,s,u,v,b[100002],mx=0;
L a[100002],ans=0;
vector<int> g[100002],lv[100002];
queue<P> q;
priority_queue<L> hp;
int main(){
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	while(m--){
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	q.push(P(s,0));
	while(!q.empty()){
		u=q.front().F,s=q.front().S;
		q.pop();
		if(b[u])	continue;
		b[u]=1;
		mx=max(mx,s);
		lv[s].push_back(u);
		for(int i=0;i<g[u].size();i++)
			if(!b[g[u][i]])	 q.push(P(g[u][i],s+1));
	}
	for(int i=mx;i>0;i--){
		for(int j=0;j<lv[i].size();j++)
			hp.push(a[lv[i][j]]);
		if(!hp.empty()){
			if(hp.top()>0)  ans+=hp.top();
			hp.pop();
		}
	}
	for(int i=1;i<=n;i++)
        if(!b[i] && a[i]>0)
            ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}
