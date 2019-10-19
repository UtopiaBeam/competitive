#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[2002],b[2002];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)   a[i]+=a[i-1];
}
