#include<cstdio>
#include<vector>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
vector<P> v;
int n,m,a[300002],s=0,t,x,chk[300002];
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&t,&x);
        if(t==1)
            v.push_back(P(x,1)),a[x]++,s++;
        if(t==2)
            v.push_back(P(x,1)),s-=a[x],a[x]=0,chk[x]=1;
        if(t==3){
            for(int i=0;i<x && i<v.size();i++){
                if(chk[v[i].F])
                    chk[v[i].F]=0,v[i].S=0;
                else if(v[i].S)
                    v[i].S=0,s--;
            }
        }
        printf("%d\n",s);
    }
    return 0;
}
