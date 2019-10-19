#include <cstdio>
int t,n,c,s;
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d %d %d",&n,&c,&s);
		printf("Case #%d: ",i);
		if(n==s)
			for(int i=1;i<=s;i++)
				printf("%d ",i);
		printf("\n");
	}
	return 0;
}