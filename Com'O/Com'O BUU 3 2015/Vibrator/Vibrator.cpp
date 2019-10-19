#include <cstdio>
int n,c,dp[50002],a[50002];
int main(){
	scanf("%d %d",&c,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		dp[a[i]]=1;
	}
}