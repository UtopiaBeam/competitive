#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,a[1000002],s,e,mn=1<<30;
int main(){
    scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d %d",&s,&e);
        if(s>e)     swap(s,e);
        a[s]++,a[e+1]--;
    }
    for(int i=1;i<=1000000;i++)
        a[i]+=a[i-1];
    for(int i=0;i<=1000000;i++)
        if(a[i]==n)     mn=min(mn,abs(x-i));
    if(mn==1<<30)       printf("-1\n");
    else        printf("%d\n",mn);
    return 0;
}
