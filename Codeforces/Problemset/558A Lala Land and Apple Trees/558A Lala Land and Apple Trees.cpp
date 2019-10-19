#include<cstdio>
#include<algorithm>
#include<vector>
#define F first
#define S second
#define P pair<int,int>
using namespace std;
vector<P > a,b;
int n,x,t,ans=0;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&x,&t);
        if(x<0)     b.push_back(P(-x,t));
        else        a.push_back(P(x,t));
    }
    sort(a.begin(),a.end()),sort(b.begin(),b.end());
    for(int i=0;i<min(a.size(),b.size());i++)
        ans+=a[i].S+b[i].S;
    if(a.size()>b.size())  ans+=a[b.size()].S;
    if(a.size()<b.size())  ans+=b[a.size()].S;
    printf("%d\n",ans);
    return 0;
}
