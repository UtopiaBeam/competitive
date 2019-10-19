#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define L long long
using namespace std;
struct S{
    int x,y,op;
    L k;
    S(int x=0,int y=0,int op=0,L k=0):
        x(x),y(y),op(op),k(k){}
};
int t,n,q,sx,sy,ex,ey;
L ft[10000002],ans[50002],k;
vector<S> v;
bool cmp(S p,S q){
    if(p.y!=q.y)    return p.y < q.y;
    if(p.op!=q.op)  return p.op < q.op;
    return p.x < q.x;
}
void ud(int x,L v){
    for(;x<=10000000;x+=-x&x)   ft[x]+=v;
}
L gs(int x){
    L sum=0;
    for(;x;x-=-x&x)     sum+=ft[x];
    return sum;
}
int main(){
    scanf("%d",&t);
    while(t--){
        memset(ft,0,sizeof(ft));
        memset(ans,0,sizeof(ans));
        v.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d %lld",&sx,&sy,&k);
            v.push_back(S(sx+1,sy+1,0,k));
        }
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
            v.push_back(S(sx,sy,1,i));
            v.push_back(S(sx,ey+1,2,i));
            v.push_back(S(ex+1,sy,2,i));
            v.push_back(S(ex+1,ey+1,1,i));
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            if(v[i].op==0)      ud(v[i].x,v[i].k);
            if(v[i].op==1)      ans[v[i].k]+=gs(v[i].x);
            if(v[i].op==2)      ans[v[i].k]-=gs(v[i].x);
        }
        for(int i=0;i<q;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
