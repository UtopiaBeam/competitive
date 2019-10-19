#include<cstdio>
#include<algorithm>
using namespace std;
int l[100002],r[100002],n;
long long a[100002];
int main(){
    while(scanf("%d",&n) && n){
        long long mx=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            l[i]=i-1;
            while(l[i]>0 && a[i]<=a[l[i]])
                l[i]=l[l[i]];
        }
        for(int i=n;i>0;i--){
            r[i]=i+1;
            while(r[i]<=n && a[i]<=a[r[i]])
                r[i]=r[r[i]];
        }
        for(int i=1;i<=n;i++)
            mx=max(mx,a[i]*(r[i]-l[i]-1));
        printf("%lld\n",mx);
    }
}
