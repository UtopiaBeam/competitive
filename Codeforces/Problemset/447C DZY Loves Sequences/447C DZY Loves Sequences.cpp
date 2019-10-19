#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100002],l[100002],r[100002],mx=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        if(a[i]>a[i-1])     l[i]=l[i-1]+1;
        else        l[i]=1;
    for(int i=n;i>0;i--)
        if(a[i]<a[i+1])     r[i]=r[i+1]+1;
        else        r[i]=1;
    for(int i=1;i<=n;i++)
        if(a[i-1]+1<a[i+1])     mx=max(mx,l[i-1]+r[i+1]+1);
        else        mx=max(mx,max(l[i-1],r[i+1])+1);
    printf("%d\n",mx);
    return 0;
}
