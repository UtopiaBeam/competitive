#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> g[100002];
int n,m,s[100002],e[100002],c[100002],d[100002];
bool chk(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!d[i]){
            q.push(i);  c[i]=1;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                d[u]=1;
                for(int i=0;i<g[u].size();i++){
                    if(c[g[u][i]]==c[u])    return false;
                    if(c[g[u][i]]==0){
                        c[g[u][i]]=-c[u];   q.push(g[u][i]);
                    }
                }
            }
        }
    }
    return true;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)   scanf("%d %d",&s[i],&e[i]);
    int l=1,r=m;
    while(l<r){
        int mid=(l+r+1)/2;
        for(int i=1;i<=n;i++)   g[i].clear(),c[i]=0,d[i]=0;
        for(int i=0;i<mid;i++)
            g[s[i]].push_back(e[i]),g[e[i]].push_back(s[i]);
        if(chk())   l=mid;
        else        r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}
