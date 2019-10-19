#include<cstdio>
long long a[105],b[105],c[105],d[105],t,ans;
int n,m;
long long f1(long long time){
    long long cnt=0;
    for(int i=0;i<n;i++)
        if(a[i]<=time)  cnt+=(time-a[i])/b[i]+1;
    return cnt;
}
long long f2(long long time){
    long long cnt=0;
    for(int i=0;i<m;i++)
        if(c[i]<=time)  cnt+=(time-c[i])/d[i]+1;
    return cnt;
}
int main(){
    scanf("%lld %d",&t,&n);
    for(int i=0;i<n;i++)
        scanf("%lld %lld",&a[i],&b[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
        scanf("%lld %lld",&c[i],&d[i]);
    long long l=1,r=t;
    while(l<r){
        long long mid=(l+r+1)/2,amnt1=f1(mid),amnt2=f2(t-mid);
        if(amnt1==amnt2){
            ans=mid;    break;
        }
        else if(amnt1<amnt2)    ans=mid,l=mid;
        else    r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
