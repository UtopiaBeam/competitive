#include<cstdio>
#include<queue>
using namespace std;
struct S{
    int s,e,w;
    bool operator<(const S &a) const{
        return w > a.w;
    }
    S(int s,int e,int w):
        s(s),e(e),w(w){}
};
priority_queue<S> h;
int n,m,s,e,w,ans=0,a[100002],r[100002];
int f(int u){
    if(u!=r[u])     r[u]=f(r[u]);
    return r[u];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        r[i]=i;
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d %d",&s,&e);
        h.push(S(s,e,a[s]+a[e]));
    }
    while(!h.empty()){
        int s=h.top().s,e=h.top().e,w=h.top().w;
        h.pop();
        int rs=f(s),re=f(e);
        if(rs!=re)  ans+=w;
        r[rs]=re;
    }
    printf("%d\n",ans);
    return 0;
}
