#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,t,a[100005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&t);
        printf("%d\n",lower_bound(a+1,a+n+1,t)-a);
    }
    return 0;
}
