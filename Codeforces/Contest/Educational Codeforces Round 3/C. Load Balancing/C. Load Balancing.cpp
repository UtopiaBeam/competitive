#include<cstdio>
#include<algorithm>
using namespace std;
int n,sum=0,a[100002],ans=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a,a+n);
    for(int i=0;i<sum%n;i++)
        a[i]++;
    sort(a,a+n);
    for(int i=0;a[i]<sum/n;i++)
        ans+=sum/n-a[i];
    printf("%d\n",ans);
    return 0;
}
