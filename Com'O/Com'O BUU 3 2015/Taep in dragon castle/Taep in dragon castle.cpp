#include <cstdio>
#include <cstring>
int q,r,c,t,p,dp[2][22][22],s[5][2]={{0,0},{0,-1},{0,1},{-1,0},{1,0}};
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	scanf("%d",&q);
	while(q--){
		scanf("%d %d %d %d",&r,&c,&t,&p);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				dp[1][i][j]=1;
		for(int k=2;k<=t;k++)
			for(int i=1;i<=r;i++)
				for(int j=1;j<=c;j++){
					dp[k%2][i][j]=0;
					for(int x=0;x<5;x++){
						dp[k%2][i][j]+=dp[(k+1)%2][i+s[x][0]][j+s[x][1]];
						dp[k%2][i][j]%=p;
					}
				}
		int sum=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++){
				sum+=dp[t%2][i][j];
				sum%=p;
			}
		printf("%d\n",sum);
	}
	return 0;
}