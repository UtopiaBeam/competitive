#include<cstdio>
long long a[1000005],ans=0;
int n,min=0;
int main(){
    scanf("%d",&n);
    int top=n/2;
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<n;i++)
        if(a[i]<a[min])     min=i,top=(min+n/2)%n;
        else if(a[i]==a[min] && (min+n/2)%n<=top)     min=i,top=(min+n/2)%n;
    for(int i=1;i<=n/2;i++){
        if(i==n/2)  ans+=a[(min+i)%n]*i;
        else    ans+=(a[(min+i)%n]+a[(min-i+n)%n])*i;
    }
    printf("%d %lld\n",top+1,ans);
    return 0;
}
