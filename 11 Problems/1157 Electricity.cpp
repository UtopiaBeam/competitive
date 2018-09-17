#include<cstdio>
#include<set>
using namespace std;
int a[500005],dp[500005],n,k;
multiset <int> b;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dp[1]=a[1];
    b.insert(dp[1]);
    for(int i=2;i<=n;i++){
        dp[i]=a[i]+*(b.begin());
        if(i>k)    b.erase(b.find(dp[i-k]));
        b.insert(dp[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}
