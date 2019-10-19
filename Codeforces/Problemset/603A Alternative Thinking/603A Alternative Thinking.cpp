#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans=1;
char a[100002];
int main(){
    scanf("%d %s",&n,a);
    for(int i=1;i<n;i++)
        ans+=(a[i]!=a[i-1]);
    printf("%d\n",min(ans+2,n));
    return 0;
}
