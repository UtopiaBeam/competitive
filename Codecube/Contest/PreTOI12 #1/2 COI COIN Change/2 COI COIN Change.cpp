#include<cstdio>
int dp[1000002],a[12],b[12],p,m,k;
int main(){
	scanf("%d %d %d",&p,&m,&k);
	for(int i=1;i<=m;i++)
		dp[i]=1<<30;
	for(int i=0;i<k;i++){
		scanf("%d",&a[i]);
		dp[a[i]]=1;
	}
	for(int i=1;i<=m;i++)
        for(int j=0;j<k;j++){
            if(i+a[j]>m)    continue;
            if(dp[i+a[j]]>dp[i]+1)
                dp[i+a[j]]=dp[i]+1;
        }
	int mn=p;
	for(int i=p+1;i<=m;i++)
		if(dp[mn]+dp[mn-p]>dp[i]+dp[i-p])
			mn=i;
	printf("%d %d\n",dp[mn],dp[mn-p]);
	int t=mn;
	while(t>0){
		for(int i=0;i<k;i++){
			if(t<a[i])	  continue;
			if(dp[t]==dp[t-a[i]]+1){
				b[i]++;
				t-=a[i];
				break;
			}
		}
	}
	for(int i=0;i<k;i++){
		printf("%d ",b[i]);
		b[i]=0;
	}
	printf("\n");
	t=mn-p;
	while(t>0){
		for(int i=0;i<k;i++){
			if(t<a[i])	  continue;
			if(dp[t]==dp[t-a[i]]+1){
				b[i]++;
				t-=a[i];
				break;
			}
		}
	}
	for(int i=0;i<k;i++){
		printf("%d ",b[i]);
		b[i]=0;
	}
	printf("\n");
	return 0;
}
