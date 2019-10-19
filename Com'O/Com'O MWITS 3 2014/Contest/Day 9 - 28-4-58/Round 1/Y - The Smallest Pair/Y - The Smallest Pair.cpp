#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[100005];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        printf("%d\n",a[0]+a[1]);
    }
    return 0;
}
