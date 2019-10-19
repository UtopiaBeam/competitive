#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,mx=0;
long long a[100002];
map<long long,int> m;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
        a[i]+=a[i-1];
        m[a[i]]++;
        mx=max(mx,m[a[i]]);
    }
    printf("%d\n",n-mx);
    return 0;
}
