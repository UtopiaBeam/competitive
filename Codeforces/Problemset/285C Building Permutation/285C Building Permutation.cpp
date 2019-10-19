#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long a[300002],ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        ans+=abs(a[i]-i);
    printf("%I64d\n",ans);
    return 0;
}
