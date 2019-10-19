#include<cstdio>
#include<algorithm>
using namespace std;
long long a[5];
int main(){
    for(int i=0;i<3;i++)
        scanf("%I64d",a+i);
    long long mn=1<<30;
    for(int i=0;i<3;i++)
        mn=min(mn,a[i]);
    for(int i=0;i<3;i++)
        a[i]-=mn;
    sort(a,a+3);
    long long mx=0;
    for(int i=0;i<3;i++)
        mx=max(mx,a[i]);
    if(mx<=1){
        printf("0\n");      return 0;
    }
    long long cnt=0;
    for(int i=0;i<3;i++)
        if(a[i]<mx)     cnt+=mx-1-a[i];
    printf("%I64d\n",cnt);
    return 0;
}
