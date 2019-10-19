#include<cstdio>
#include<algorithm>
using namespace std;
int a[20002],b[20002],dp[20002],n,m,k;
int main(){
    scanf("%d %d %d",&k,&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[++n]=k;
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        int t=min(i,m);
        for(int j=t;j>0;j--)
            dp[j]=max(dp[j-1],dp[j])+b[j]*(a[i]-a[i-1]);
    }
    printf("%d\n",dp[m]);
    return 0;
}
