//BFS
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
vector <int> adj[70];
queue <PII> q;
int m,s,e,mark[70],Min=1<<20;
int main(){
    scanf("%d %d %d",&m,&s,&e);
    while(m--){
        int str,end;
        scanf("%d %d",&str,&end);
        adj[str].push_back(end),adj[end].push_back(str);
    }
    q.push(PII(s,0));   //EndNode,Distance
    while(!q.empty()){
        int now=(q.front()).first,w=(q.front()).second;
        q.pop();
        if(now==e && w<Min)    Min=w;
        if(!mark[now]){
            mark[now]=1;
            for(int i=0;i<(int)adj[now].size();i++)
                q.push(PII(adj[now][i],w+1));
        }
    }
    printf("%d\n",Min);
    return 0;
}
