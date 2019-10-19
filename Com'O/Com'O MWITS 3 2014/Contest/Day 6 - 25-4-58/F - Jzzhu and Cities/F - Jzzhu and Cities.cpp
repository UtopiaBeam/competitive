#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
vector <PII> adj[200005],train[200005];
priority_queue <PII> q;
int n,m,k,s,e,mark[200005],cnt=0;
long long w,d[200005];
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        d[i]=1<<30;
    while(m--){
        scanf("%d %d %I64d",&s,&e,&w);
        adj[s].push_back(PII(e,w)),adj[e].push_back(PII(s,w));
    }
    while(k--){
        scanf("%d %I64d",&e,&w);
        train[1].push_back(PII(e,w)),train[e].push_back(PII(1,w));
    }
    q.push(PII(0,1));
    while(!q.empty()){
        int w=-(q.top()).first,i=(q.top()).second;
        q.pop();
        if(!mark[i]){
            mark[i]=1,d[i]=w;
            for(int j=0;j<adj[i].size();j++)
                if(!mark[adj[i][j].first] && d[adj[i][j].first]>w+adj[i][j].second)
                    q.push(PII(-(w+adj[i][j].second),adj[i][j].first));
        }
    }
    q.push(PII(0,1));
    while(!q.empty()){
        int w=-(q.top()).first,i=(q.top()).second;
        q.pop();
        if(mark[i]){
            mark[i]=0,d[i]=w;
            for(int j=0;j<train[i].size();j++)
                if(mark[train[i][j].first]){
                    if(d[train[i][j].first]>w+train[i][j].second)
                        q.push(PII(-(w+train[i][j].second),train[i][j].first));
                    else    cnt++;
                }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
