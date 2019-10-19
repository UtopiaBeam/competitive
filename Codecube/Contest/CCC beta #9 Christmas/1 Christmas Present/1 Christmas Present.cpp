#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[102],b[102];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<m;i++)
        scanf("%d",b+i);
    sort(a,a+n);
    sort(b,b+m);
    int mn=100+a[0]+b[0];
    if(n>1)     mn=min(mn,a[0]+a[1]);
    if(m>1)     mn=min(mn,b[0]+b[1]);
    printf("%d\n",mn);
    return 0;
}
