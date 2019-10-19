#include<cstdio>
#include<algorithm>
using namespace std;
int n,cnt=0;
char a[1005],b[1005];
int main(){
    scanf("%d %s %s",&n,a,b);
    for(int i=0;a[i];i++)
        if(a[i]<=b[i])  cnt+=min(b[i]-a[i],a[i]+10-b[i]);
        else    cnt+=min(a[i]-b[i],b[i]+10-a[i]);
    printf("%d\n",cnt);
    return 0;
}
