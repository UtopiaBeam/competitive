#include<cstdio>
#include<algorithm>
using namespace std;
int q,n,a[25],dp[25],mx=-10;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[j]<a[i])   dp[i]=max(dp[i],dp[j]+1);
    for(int i=0;i<n;i++)
        mx=max(mx,dp[i]);
    printf("%d\n",mx);
    return 0;
}
