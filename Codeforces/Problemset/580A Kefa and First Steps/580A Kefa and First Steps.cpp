#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005],mx=1,cnt=1;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        if(a[i]>=a[i-1])    cnt++;
        else    cnt=1;
        mx=max(mx,cnt);
    }
    printf("%d\n",mx);
    return 0;
}
