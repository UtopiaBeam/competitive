#include<cstdio>
int n,m,t,x,y,v,ft[200002];
void upd(int x,int v){
    for(;x<=n;x+=-x&x)      ft[x]+=v;
}
int get(int x){
    int sum=0;
    for(;x;x-=-x&x)     sum+=ft[x];
    return sum;
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d",&t);
        if(t==1){
            scanf("%d %d %d",&x,&y,&v);
            upd(x,v);   upd(y+1,-v);
        }
        else{
            scanf("%d",&x);
            printf("%d\n",get(x));
        }
    }
    return 0;
}
