#include <cstdio>
#include <algorithm>
using namespace std;
struct S{
	int c[52];
}r[52];
int t,n,a[52][52],chk[2][52][52],nr=0,nc=0;
bool cmp(S a,S b){
	for(int i=0;i<n;i++)
		if(a.c[i]!=b.c[i])
			return a.c[i]<b.c[i];
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		scanf("%d",&n);
		for(int i=1;i<2*n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&r[i].c[j]);
		sort(r+1,r+2*n,cmp);
		printf("Case #%d:\n",q);
		for(int i=1;i<2*n;i++){
			for(int j=0;j<n;j++)
				printf("%d ",r[i].c[j]);
			printf("\n");
		}
	}
	return 0;
}