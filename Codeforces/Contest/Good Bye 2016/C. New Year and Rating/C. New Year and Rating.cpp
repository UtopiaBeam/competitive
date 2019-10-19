#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 1<<25
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n;
int c[200002],d[200002];
vector<P> v;
int chk(int x){
    for(int i=n-1;i>=0;i--){
        x-=c[i];
        if(x>=1900 && d[i]==2)
            return -1;
        if(x<1900 && d[i]==1)
            return 1;
    }
    return 0;
}
int bs(int s,int e){
    if(s==e)    return s;
    int m=(s+e+1)/2;
    int st=chk(m);
    if(st==0)   return bs(m,e);
    if(st==1)   return bs(m+1,e);
    return bs(s,m-1);
}
bool isPos(){
    int x=0;
    for(int i=0;i<n;i++){
        v.push_back(P(x,d[i]));
        x+=c[i];
    }
    sort(v.begin(),v.end());
    int nw=0;
    for(int i=0;i<v.size();i++){
        if(nw==0)   nw=v[i].S;
        if(nw==2 && v[i].S==1)
            nw=1;
        else if(nw==1 && v[i].S==2)
            return false;
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",c+i,d+i);
    if(!isPos()){
        printf("Impossible\n");
        return 0;
    }
    int ans=bs(0,INF);
    if(ans==INF)        printf("Infinity\n");
    else                printf("%d\n",ans);
    return 0;
}
