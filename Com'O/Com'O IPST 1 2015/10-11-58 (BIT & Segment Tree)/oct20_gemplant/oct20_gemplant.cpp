#include<cstdio>
int n,m,t,x,y,ft[200002];
void upd(int i,int v){
    for(;i<=n;i+=-i&i)      ft[i]+=v;
}
int get(int s,int e){
    int sum=0;
    s--;
    for(;e;e-=-e&e)     sum+=ft[e];
    for(;s;s-=-s&s)     sum-=ft[s];
    return sum;
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&t,&x,&y);
        if(t==1)    upd(y,x);
        else        printf("%d\n",get(x,y));
    }
    return 0;
}
