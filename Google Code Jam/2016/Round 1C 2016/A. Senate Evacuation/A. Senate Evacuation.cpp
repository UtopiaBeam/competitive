#include <cstdio>
int q,n,a[30];
int main(){
	freopen("A-large.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&q);
	for(int t=1;t<=q;t++){
		printf("Case #%d: ",t);
		int sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%2){
			int mx=0;
			for(int i=1;i<n;i++)
				if(a[mx]<a[i])	mx=i;
			printf("%c ",mx+'A');
			a[mx]--,sum--;
		}
		while(true){
			int mx=0;
			for(int i=1;i<n;i++){
				// if(a[i]!=0)		chk=0;
				if(a[mx]<a[i])	mx=i;
			}
			if(!sum)		break;
			printf("%c",mx+'A');
			a[mx]--,sum--;
			mx=0;
			for(int i=1;i<n;i++){
				// if(a[i]!=0)		chk=0;
				if(a[mx]<a[i])	mx=i;
			}
			if(!sum)		break;
			printf("%c ",mx+'A');
			a[mx]--,sum--;
			// for(int i=0;i<n;i++)
			// 	printf("%c = %d\n",i+'A',a[i]);
		}
		printf("\n");
	}
	return 0;
}
