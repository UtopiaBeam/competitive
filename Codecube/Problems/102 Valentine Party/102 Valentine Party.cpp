#include<cstdio>
#define L long long
L ft[1000002],d,a[1000002];
int n,p,m,k,q,x;
void ud(int x,L v){
    for(;x<=n;x+=-x&x)  ft[x]+=v;
}
L qr(int x){
    L sm=0;
    for(;x;x-=-x&x)     sm+=ft[x];
    return sm;
}
int main(){
    scanf("%d %d",&n,&p);
    for(int i=1;i<=n;i++)
        a[i]=10000;
    while(p--){
        scanf("%d %d %lld %d",&m,&k,&d,&q);
        int s=m-k,e=m+k;
        if(s<1)     s=n+s;
        if(e>n)     e=e-n;
//        printf("%d %d\n",s,e);
        if(s<=e){
            ud(s,-d);   ud(e+1,d);
        }
        else{
            ud(1,-d);   ud(e+1,d);
            ud(s,-d);
        }
//        for(int i=1;i<=n;i++)
//            printf("%lld ",qr(i));
//        printf("\n");
        while(q--){
            scanf("%d",&x);
            L c=qr(x);
            if(a[x]+c<=0)   printf("0 ");
            else    printf("%lld ",a[x]+c);
        }
        printf("\n");
    }
    return 0;
}
