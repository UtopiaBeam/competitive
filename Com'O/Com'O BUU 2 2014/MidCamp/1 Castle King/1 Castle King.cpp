/*
TASK: Castle King
LANG: C++
AUTHOR: Natchapol Srisang
CENTER: Princess Chulabhron's College, Chonburi
*/
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500010],maxh=-1<<20,ans,n,i,j=0;
int main(){
    scanf("%d",&n);
    ans=n;
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        maxh=max(a[i],maxh);
        ans+=2*a[i];
    }
    ans+=2*maxh;
    printf("%lld\n",ans);
    return 0;
}
