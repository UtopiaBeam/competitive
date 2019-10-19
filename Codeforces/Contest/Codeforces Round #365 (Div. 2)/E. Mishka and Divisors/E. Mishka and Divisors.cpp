#include<cstdio>
#include<algorithm>
#define L long long
#define P pair<L,int>
#define F first
#define S second
using namespace std;
int n,chk[1002],cnt=0;
L k,p=1;
P a[1002];
int main(){
    scanf("%d %I64d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%I64d",&a[i].F);
        a[i].S=i+1;
        p*=a[i].F;
    }
    if(p%k){
        printf("-1\n");
        return 0;
    }
    p/=k;
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        if(!(p%a[i].F)){
            chk[i]=1;   cnt++;
            p/=a[i].F;
        }
    }
    printf("%d\n",n-cnt);
    for(int i=0;i<n;i++)
        if(!chk[i])     printf("%d ",a[i].S);
    return 0;
}
