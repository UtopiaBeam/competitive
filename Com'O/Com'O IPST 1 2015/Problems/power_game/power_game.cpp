#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100002],b[100002],sum=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)    scanf("%d",&a[i]),a[i]=-a[i];
    for(int i=0;i<n;i++)    scanf("%d",&b[i]),b[i]=-b[i];
    sort(a,a+n);    sort(b,b+n);
    int na=0,nb=0;
    while(na<n && nb<n){
        if(a[na]<b[nb]) sum-=a[na++];
        nb++;
    }
    printf("%d\n",sum);
    return 0;
}
