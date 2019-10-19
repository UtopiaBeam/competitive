#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[810],b[810],ans=0;
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    sort(a,a+n);    sort(b,b+n);
    for(i=0;i<n;i++)
        ans+=a[i]*b[n-1-i];
    printf("%d\n",ans);
    return 0;
}
