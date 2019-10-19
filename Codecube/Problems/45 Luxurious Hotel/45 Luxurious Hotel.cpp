#include<cstdio>
#include<algorithm>
using namespace std;
int a[100002],dp[100002][2],n,k,p;
int main(){
	scanf("%d %d %d",&n,&k,&p);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
    for(int j=1;j<=k;j++)
        for(int i=1;i<=n;i++)
			if(i>=p) dp[i][j%2]=max(dp[i-1][j%2],dp[i-p][(j+1)%2]+a[i]-a[i-p]);
			else     dp[i][j%2]=max(dp[i-1][j%2],a[i]);
	printf("%d\n",dp[n][k%2]);
	return 0;
}
