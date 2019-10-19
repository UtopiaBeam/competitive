#include<cstdio>
#include<algorithm>
using namespace std;
int n,l=0,r=-1;
long long k,a[300005],mx=0,sum=0;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i);
    while(l<n && ++r<n){
        sum+=a[r];
        while(sum>k && l<=r)
            sum-=a[l++];
        mx=max(mx,sum);
    }
    printf("%lld\n",mx);
    return 0;
}
