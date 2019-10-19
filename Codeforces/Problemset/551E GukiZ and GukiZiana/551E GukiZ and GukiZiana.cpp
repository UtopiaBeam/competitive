#include<cstdio>
long long ft[500005],n,q,t,l,r,x;
void up(int x,int v){
    for(;x<=n;x+=(x&-x))    ft[x]+=v;
}
int main(){
    scanf("%I64d %I64d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&t);
        up(i,t);
    }
    while(q--){
        scanf("%I64d",&t);
        if(t==1){
            scanf("%I64d %I64d %I64d",&l,&r,&x);
            up(l,x);    up(r+1,-x);
        }
        else{
            scanf("%I64d",&x);
            //
        }
    }
    return 0;
}
