#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define P pair<int,int>
#define F first
#define S second
vector<P> g[55];
priority_queue<P> q;
int n,d[55],w,b[55],mn=(int)1e9,ans;
char s,e;
int f(char x){
    if(x=='Z')      return 0;
    if(x>='A' && x<'Z')    return x-'A'+1;
    return x-'a'+26;
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf(" %c %c %d",&s,&e,&w);
        g[f(s)].push_back(P(f(e),w));
        g[f(e)].push_back(P(f(s),w));
    }
    for(int i=0;i<55;i++)   d[i]=(int)1e9;
    q.push(P(0,0));
    while(!q.empty()){
        int u=q.top().S,t=-q.top().F;
        q.pop();
        if(!b[u]){
            b[u]=1;     d[u]=t;
            for(int i=0;i<g[u].size();i++)
                if(!b[g[u][i].F] && t+g[u][i].S<d[g[u][i].F])
                    q.push(P(-t-g[u][i].S,g[u][i].F));
        }
    }
    for(int i=1;i<26;i++)
        if(mn>d[i])     mn=d[i],ans=i;
    printf("%c %d\n",ans+'A'-1,mn);
    return 0;
}
