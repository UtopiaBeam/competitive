#include<cstdio>
#include<vector>
#include<queue>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
priority_queue<P> q;
vector<int> v;
int n,m,t,chk[100005];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        q.push(P(t,i));
    }
    while(m--){
        v.clear();
        int cnt=0,nw;
        scanf("%d",&t);
        while(!q.empty() && q.top().F>t){
            nw=q.top().S;
            if(!chk[nw]){
                v.push_back(nw);
                if(nw>0 && !chk[nw-1])      v.push_back(nw-1);
                if(nw<n-1 && !chk[nw+1])    v.push_back(nw+1);
            }
            q.pop();
        }
        for(int i=0;i<v.size();i++)
            if(!chk[v[i]])  chk[v[i]]=1,cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
