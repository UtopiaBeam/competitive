#include<cstdio>
#include<algorithm>
int n,k,a[100002],mx=0;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<std::min(n,2*k-n);i++)
        mx=std::max(mx,a[n-i]);
    for(int i=1;i<=std::min(n,2*(n-k));i++)
        mx=std::max(mx,a[i]+a[std::min(n,2*(n-k)-i+1)]);
    printf("%d\n",mx);
    return 0;
}
