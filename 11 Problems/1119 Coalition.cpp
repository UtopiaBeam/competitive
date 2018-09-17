#include<cstdio>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
P a[300005];
int n,sum=0,b[300005],ans[300005],pnt,t;
bool cmp(P x,P y){
    if(x.F!=y.F)    return x.F>y.F;
    return x.S<y.S;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].F);
        sum+=a[i].F;
        a[i].S=i;
    }
    sum=sum/2+1;
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
        b[i]=a[i].F+(i>0)*b[i-1];
    pnt=lower_bound(b,b+n,sum)-b;
    for(int i=0;i<=pnt;i++)
        ans[a[i].S]=pnt;
    for(int i=pnt+1;i<n;i++){
        t=pnt;
        while(t>0 && b[t-1]+a[i].F>=sum)  t--;
        ans[a[i].S]=t+1;
    }
    for(int i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
