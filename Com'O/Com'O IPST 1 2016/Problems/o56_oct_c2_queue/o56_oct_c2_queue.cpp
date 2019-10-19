#include<cstdio>
#include<queue>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
priority_queue<P> q;
int n=0,m,c,x,ft[100002],a[200002];
void ud(int x,int v){
    for(;x<=100000;x+=-x&x) ft[x]+=v;
}
int qr(int x){
    int sum=0;
    for(;x;x-=-x&x)     sum+=ft[x];
    return sum;
}
int main(){
    scanf("%d",&m);
    while(m--){
        scanf("%d",&c);
        if(c==1){
            scanf("%d",&x);
            a[++n]=x;
            q.push(P(-x,n));
            ud(x,1);
        }
        if(c==2){
            if(q.empty())   printf("0\n");
            else{
                printf("%d\n",q.top().S);
                ud(-q.top().F,-1);
                q.pop();
            }
        }
        if(c==3){
            scanf("%d",&x);
            printf("%d\n",qr(a[x]-1));
        }
    }
    return 0;
}
