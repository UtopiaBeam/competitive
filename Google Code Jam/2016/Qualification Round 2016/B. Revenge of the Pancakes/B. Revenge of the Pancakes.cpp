#include <cstdio>
#include <cstring>
int t;
char a[105];
int main(){
	freopen("B-large.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		scanf(" %s",a);
		int cnt=0;
		strcat(a,"+");
		for(int i=1;a[i];i++)
			if(a[i]!=a[i-1])
				cnt++;
		printf("Case #%d: %d\n",q,cnt);
	}
	return 0;
}