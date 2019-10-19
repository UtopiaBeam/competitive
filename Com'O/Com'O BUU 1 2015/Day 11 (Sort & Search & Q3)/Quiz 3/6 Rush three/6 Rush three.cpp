#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100002];
int main(){
    scanf("%d",&n);
    int l=0,r=n-1,sum=0;;
    for(int i=0;i<n;i++)    scanf("%d",&a[i]);
    sort(a,a+n);
    while(l<r-2)    sum+=a[l]+a[l+1]+a[r],l+=2,r-=2;
    while(l<=r) sum+=a[l++];
    printf("%d\n",sum);
    return 0;
}
