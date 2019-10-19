#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005],q,t;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&t);
        int in=lower_bound(a+1,a+n+1,t)-a;
        printf("%d\n",in);
    }
    return 0;
}
