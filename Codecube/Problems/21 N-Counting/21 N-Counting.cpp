#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct S{
    int val,idx,id,op;
    S(int val=0,int idx=0,int id=0,int op=0):
        val(val),idx(idx),id(id),op(op){}
};
int n,m,ft[20002],ans[200002],x,y,s,e,t;
vector<S> v;
bool cmp(S x,S y){
    if(x.val!=y.val)    return x.val<y.val;
    return x.op<y.op;
}
void ud(int x){
    for(;x<=n;x+=-x&x)  ft[x]++;
}
int qr(int x){
    int sum=0;
    for(;x;x-=-x&x)     sum+=ft[x];
    return sum;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        v.push_back(S(t,i));
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d %d",&s,&e,&x,&y);
        v.push_back(S(x-1,s-1,i,1));
        v.push_back(S(x-1,e,i,2));
        v.push_back(S(y,s-1,i,2));
        v.push_back(S(y,e,i,1));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        if(v[i].op==0)  ud(v[i].idx);
        if(v[i].op==1)  ans[v[i].id]+=qr(v[i].idx);
        if(v[i].op==2)  ans[v[i].id]-=qr(v[i].idx);
    }
    for(int i=0;i<m;i++)
        printf("%d ",ans[i]);
    return 0;
}
