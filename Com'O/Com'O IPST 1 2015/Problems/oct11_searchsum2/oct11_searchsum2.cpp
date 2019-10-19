#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,m,a[1002],b[1002];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)    scanf("%d",&b[i]),a[i]=1e9;
    for(int i=1;i<n;i++)    b[i]+=b[i-1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<n-i;j++)
            a[i]=min(a[i],b[j+i]-(j>0)*b[j-1]);
    while(k--){
        scanf("%d",&m);
        printf("%d\n",upper_bound(a,a+n,m)-a);
    }
    return 0;
}
