#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100002],b[100002],mx=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)    scanf("%d",&a[i]);
    for(int i=0;i<n;i++)    scanf("%d",&b[i]);
    sort(a,a+n);    sort(b,b+n);
    for(int i=0;i<n;i++)
        mx=max(mx,min(a[i],b[n-i-1]));
    printf("%d\n",mx);
    return 0;
}
