#include<cstdio>
#include<cstring>
#include<vector>
#define P pair<int,int>
#define F first
#define S second
#define L long long
using namespace std;
int n,m,c[100002];
L a[100002],b[100002];
bool chk(int k){
    memset(c,0,sizeof(c));
    vector<P> v;
    for(int i=k;i;i--)
        if(a[i] && !c[a[i]])    c[a[i]]=1,v.push_back(P(i,a[i]));
    if(v.size()<m)      return false;
    v.push_back(P(0,0));
    L d=0;
    for(int i=v.size()-2;i>=0;i--){
        d+=v[i].F-v[i+1].F-1;
        if(d<b[v[i].S])     return false;
        else    d-=b[v[i].S];
    }
    return true;
}
int bs(int s,int e){
    if(s==e){
        if(s<=n)    return s;
        return -1;
    }
    int m=(s+e)/2;
    if(chk(m))      return bs(s,m);
    return bs(m+1,e);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=m;i++)
        scanf("%d",b+i);
    printf("%d\n",bs(1,n+1));
    return 0;
}
