#include<cstdio>
using namespace std;
int a[55],n,k,cnt=0;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        if(a[i]<=0)  break;
        if(a[i]>=a[k-1])    cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
