#include<cstdio>
#include<queue>
#define P pair<int,int>
#define PP pair<P,P>
#define F first
#define S second
#define INF (int)1e9
using namespace std;
priority_queue<PP> h,q;
int t,b,n,m,w,v,d,x,a[100002],cnt=0;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n+m;i++){
        while(!q.empty() && -q.top().F.F<i){
            if(!a[q.top().F.S]) h.push(PP(P(q.top().S.F,q.top().S.S),P(-INF,q.top().F.S)));
            q.pop();
        }
        scanf("%d",&t);
        if(t==1){
            scanf("%d %d %d",&b,&w,&v);
            if(b==1)    h.push(PP(P(-w,v),P(-INF,cnt++)));
            else if(b==2){
                scanf("%d",&d);
                h.push(PP(P(-w,v),P(-d,cnt++)));
            }
            else{
                scanf("%d %d",&d,&x);
                h.push(PP(P(-w,v),P(-d,cnt)));
                q.push(PP(P(-d,cnt++),P(-x,v)));
            }
        }
        else{
            while(!h.empty() && (-h.top().S.F<i || a[h.top().S.S])){
                h.pop();
            }
            if(h.empty())   printf("0\n");
            else    printf("%d\n",h.top().F.S),a[h.top().S.S]=1,h.pop();
        }
    }
    return 0;
}
