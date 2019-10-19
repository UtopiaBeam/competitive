#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#define INF 1<<20
using namespace std;
typedef pair<int,int> PII;
vector <PII> adj[10005];
priority_queue <PII> q;
stack <int> ans;
int pre[10005],d[10005];
bool isrelax[10005];
void dijs(){
    while(!q.empty()){
        int t=(-1)*(q.top()).first,now=(q.top()).second;
        q.pop();
        if(!isrelax[now]){
            isrelax[now]=true,d[now]=t;
            for(int i=0;i<(int)adj[now].size();i++)
                if(!isrelax[adj[now][i].first] && d[adj[now][i].first]>adj[now][i].second+d[now]){
                    q.push(PII((-1)*(adj[now][i].second+d[now]),adj[now][i].first));
                    pre[adj[now][i].first]=now;
                }
        }
    }
}
int main(){
    int r,n,s;
    scanf("%d %d %d",&r,&n,&s);
    for(int i=0;i<=n;i++)
        isrelax[i]=false,d[i]=INF;
    while(r--){
        int str,end,t;
        scanf("%d %d %d",&str,&end,&t);
        adj[str].push_back(PII(end,t)),adj[end].push_back(PII(str,t));
    }
    q.push(PII(0,s));
    dijs();
    printf("%d\n",d[0]);
    int now=0;
    while(1){
        ans.push(now);
        if(now==s)  break;
        now=pre[now];
    }
    while(!ans.empty()){
        printf("%d ",ans.top());
        ans.pop();
    }
    printf("\n");
    return 0;
}
