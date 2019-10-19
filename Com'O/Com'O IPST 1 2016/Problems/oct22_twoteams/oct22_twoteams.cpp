#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,s,e,c[100002];
vector<P> g[100002];
bool chk(int m){
    queue<int> q;
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++){
        if(c[i])    continue;
        q.push(i);      c[i]=1;
        while(!q.empty()){
            s=q.front();
            q.pop();
            for(int j=0;j<g[s].size();j++){
                if(g[s][j].S>m)     continue;
                if(c[g[s][j].F]==c[s])
                    return false;
                if(!c[g[s][j].F]){
                    c[g[s][j].F]=-c[s];
                    q.push(g[s][j].F);
                }
            }
        }
    }
    return true;
}
int bs(int s,int e){
    if(s==e)    return s;
    int m=(s+e+1)/2;
    if(chk(m))      return bs(m,e);
    return bs(s,m-1);
}
int main(){
    int m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&s,&e);
        g[s].push_back(P(e,i));
        g[e].push_back(P(s,i));
    }
    printf("%d\n",bs(1,m));
    return 0;
}
