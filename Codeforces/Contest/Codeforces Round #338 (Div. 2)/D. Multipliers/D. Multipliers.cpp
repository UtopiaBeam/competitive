#include<cstdio>
#include<vector>
#include<map>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
using namespace std;
int n;
ll ans=1,t,sum=1;
vector<ll> V;
map<ll,ll> M;
ll f(ll b,ll p){
    if(p==0)    return 1;
    ll x=f(b,p/2);
    if(p%2)     return (x*x*b)%MOD;
    return (x*x)%MOD;
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%I64d",&t);
        V.push_back(t);
    }
    for(int i=0;i<V.size();i++){
        if(!M[V[i]])    M[V[i]]=1;
        M[V[i]]++;
    }
    for(map<ll,ll>::iterator it=M.begin();it!=M.end();it++)
        sum*=it->S;     //Bug
    for(map<ll,ll>::iterator it=M.begin();it!=M.end();it++){
        ans*=f(it->F,(((it->S)*(it->S-1))/2)*(sum/(it->S)));
        ans%=MOD;
    }
    printf("%I64d\n",ans);
    return 0;
}
