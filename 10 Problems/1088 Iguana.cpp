#include<cstdio>
#include<map>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,m,s,e,sz=0,co,ans=0;
char ch;
P a[100005];
map<int,int> h;
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&s,&e);
        h[s]++,h[e+1]--;
    }
    a[0]=P(1,0);
    for(map<int,int>::iterator it=h.begin();it!=h.end();it++)
        a[++sz]=*it;
    for(int i=1;i<=sz;i++)
        a[i].S+=a[i-1].S;
    a[++sz]=P(n+1,0);
    if(ch=='R')     co=0;
    else if(ch=='G')    co=1;
    else    co=2;
    for(int i=0;i<sz;i++){
        a[i].S%=3,a[i].S=(a[i].S+3)%3;
        ans+=((co-a[i].S+3)%3)*(a[i+1].F-a[i].F);
    }
    printf("%d\n",ans);
    return 0;
}
