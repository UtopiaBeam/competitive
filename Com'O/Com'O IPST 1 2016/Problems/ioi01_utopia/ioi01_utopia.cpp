#include<cstdio>
#include<algorithm>
using namespace std;
int n,x[10002],y[10002],a[10002];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",x+i);
    for(int i=0;i<n;i++)
        scanf("%d",y+i);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(x,x+n);    sort(y,y+n);
    return 0;
}

