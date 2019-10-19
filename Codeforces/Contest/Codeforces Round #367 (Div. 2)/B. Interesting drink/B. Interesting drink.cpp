#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100002],t,m;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    sort(a,a+n);
    while(m--){
        scanf("%d",&t);
        printf("%d\n",upper_bound(a,a+n,t)-a);
    }
    return 0;
}
