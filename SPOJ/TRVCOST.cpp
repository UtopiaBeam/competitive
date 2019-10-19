#include<cstdio>
#include<queue>
#include<vector>
#define INF 2e9
using namespace std;
int d[505],mark[505],n,u,v,w;
vector  <pair<int,int> > adj[505];
priority_queue <pair<int,int> > q;
int main(){
    scanf("%d",&n);
    for(int i=0;i<=500;i++)     d[i]=INF;
    while(n--){
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back(make_pair(v,w)),adj[v].push_back(make_pair(u,w));
    }
    scanf("%d",&u);
    q.push(make_pair(0,u));
    while(!q.empty()){
        int cost=(q.top()).first*(-1),now=(q.top()).second;
        q.pop();
        if(!mark[now]){
            mark[now]=1,d[now]=cost;
            for(int i=0;i<adj[now].size();i++)
                if(!mark[adj[now][i].first] && d[adj[now][i].first]>cost+adj[now][i].second)
                    q.push(make_pair((-1)*(cost+adj[now][i].second),adj[now][i].first));
        }
    }
    scanf("%d",&w);
    while(w--){
        scanf("%d",&v);
        if(d[v]==INF)   printf("NO PATH\n");
        else    printf("%d\n",d[v]);
    }
    return 0;
}

