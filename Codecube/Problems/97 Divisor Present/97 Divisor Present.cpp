#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
ll n;
vector<ll> v;
int main(){
    scanf("%lld",&n);
    for(ll i=1;i*i<=n;i++)
        if(n%i==0){
            v.push_back(i);
            if(i*i!=n)      v.push_back(n/i);
        }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        printf("%lld ",v[i]);
    return 0;
}
