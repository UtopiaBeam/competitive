#include <cstdio>
int t,n;
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		int a[12]={},cnt=10;
		scanf("%d",&n);
		printf("Case #%d: ",q);
		if(n==0){
			printf("INSOMNIA\n");
			continue;
		}
		int tmp2=n;
		while(cnt){
			int tmp=tmp2;
			while(tmp){
				if(!a[tmp%10]){
					a[tmp%10]=1;
					cnt--;
				}
				tmp/=10;
			}
			tmp2+=n;
		}
		printf("%d\n",tmp2-n);
	}
	return 0;
}