#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,m,a[100002];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)    scanf("%d",&a[i]);
    for(int i=1;i<n;i++)    a[i]+=a[i-1];
    while(k--){
        scanf("%d",&m);
        printf("%d\n",upper_bound(a,a+n,m)-a);
    }
    return 0;
}
