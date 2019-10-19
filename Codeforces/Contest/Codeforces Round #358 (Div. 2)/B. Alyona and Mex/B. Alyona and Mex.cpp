#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100002],nw=1;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++)
        if(nw<=a[i])     a[i]=nw++;
    printf("%d\n",nw);
    return 0;
}
