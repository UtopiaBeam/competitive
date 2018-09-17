#include<cstdio>
#include<algorithm>
using namespace std;
int a[2010],n,k,ans=0;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i]*=-1;
    }
    sort(a,a+n);
    for(int i=0;i<n;i+=k)
        ans-=a[i];
    printf("%d\n",ans);
    return 0;
}
