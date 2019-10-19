#include<cstdio>
#include<climits>
#include<algorithm>
#define P pair<long long,int>
#define F first
#define S second
using namespace std;
int n,m,s,e,rt[100002],nw=0,l[100002],r[100002];
long long mn=INT_MAX;
P a[100002];
int find(int u){
    if(u!=rt[u]) rt[u]=find(rt[u]);
    return rt[u];
}
int main(){
    scanf("%d",&n);
    if(n==1){
        printf("0\n");      return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].F);
        a[i].S=i;   rt[i]=i;
    }
    sort(a+1,a+n+1);
    for(int i=0;i<n-2;i++){
        scanf("%d %d",&s,&e);
        rt[find(s)]=find(e);
    }
    a[0].F=INT_MIN,a[n+1].F=INT_MAX;
    nw=0;
    for(int i=2;i<=n;i++){
        if(find(a[i-1].S)!=find(a[i].S))    nw=i-1;
        l[i]=nw;
    }
    nw=n+1;   r[n]=n+1;
    for(int i=n-1;i>0;i--){
        if(find(a[i+1].S)!=find(a[i].S))    nw=i+1;
        r[i]=nw;
    }
    for(int i=1;i<=n;i++)   mn=min(mn,min(a[i].F-a[l[i]].F,a[r[i]].F-a[i].F));
    printf("%lld\n",mn);
    return 0;
}
