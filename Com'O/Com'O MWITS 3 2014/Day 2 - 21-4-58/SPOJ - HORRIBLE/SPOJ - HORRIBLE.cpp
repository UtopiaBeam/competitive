#include<cstdio>
#include<cstring>
int q,n,c;
long long t1[100005],t2[100005];
void add(long long *a,int at,long long num){
    for(;at<=n;at+=(-at&at))
        a[at]+=num;
}
void range(int s,int e,long long num){
    add(t1,s,num);      add(t1,e+1,-num);
    add(t2,s,num*(s-1));    add(t2,e+1,-num*e);
}
long long sum(long long *a,int at){
    long long sum=0;
    for(;at;at-=(-at&at))   sum+=a[at];
    return sum;
}
long long sum(int at){
    return sum(t1,at)*(long long)at-sum(t2,at);
}
long long r_sum(int s,int e){
    return sum(e)-sum(s-1);
}
int main(){
    scanf("%d",&q);
    while(q--){
        memset(t1,0,sizeof(t1));    memset(t2,0,sizeof(t2));
        scanf("%d %d",&n,&c);
        while(c--){
            int opr,s,e;
            long long num;
            scanf("%d %d %d",&opr,&s,&e);
            if(opr)     printf("%lld\n",r_sum(s,e));
            else{
                scanf("%lld",&num);
                range(s,e,num);
            }
        }
    }
    return 0;
}
