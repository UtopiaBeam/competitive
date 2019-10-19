#include <cstdio>
#include <deque>
using namespace std;
int t;
char a[1002],b[1002];
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		deque<char> ans;
		scanf(" %s",a);
		ans.push_front(a[0]);
		for(int i=1;a[i];i++)
			if(a[i]>=ans[0])
				ans.push_front(a[i]);
			else	ans.push_back(a[i]);
		// int len=strlen(a);
		// strcpy(b,a);
		// sort(b,b+len);
		printf("Case #%d: ",q);
		// printf("%s\n",b);
		for(int i=0;i<ans.size();i++)
			printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}