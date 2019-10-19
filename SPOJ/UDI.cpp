#include<cstdio>
#include<cstring>
long long a[10002],v;
int t,n,q,l,r;
int main(){
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        scanf("%d %d",&n,&q);
        while(q--){
            scanf("%d %d %lld",&l,&r,&v);
            a[l]+=v,a[r+1]-=v;
        }
        for(int i=1;i<=n;i++)   a[i]+=a[i-1];
        scanf("%d",&q);
        while(q--){
            scanf("%d",&l);
            printf("%lld\n",a[l]);
        }
    }
    return 0;
}
