#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long a[1000010],ans=0;
bool cmp(int i,int j){  return i>j; }
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    nth_element(a,a+n/2,a+n,cmp);
    for(int i=0;i<n/2;i++)
        ans+=abs(a[i]-a[n-i-1]);
    printf("%lld\n",ans);
    return 0;
}
