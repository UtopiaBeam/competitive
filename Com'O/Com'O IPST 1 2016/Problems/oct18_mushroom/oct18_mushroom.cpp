#include<cstdio>
#include<set>
#define ll long long
using namespace std;
ll l,h,x,y;
multiset<ll> ms;
multiset<ll>::iterator it;
int n,m;
int main(){
    scanf("%d %lld %lld",&m,&l,&h);
    while(m--){
        scanf("%d",&n);
        while(n--){
            scanf("%lld",&x);
            ms.insert(x);
        }
        scanf("%lld %lld",&x,&y);
        ll s=l+(x*h)/y+((x*h)%y>0)*(x>=0);
        it=ms.lower_bound(s);
        ms.erase(it,ms.end());
        printf("%d\n",ms.size());
    }
    return 0;
}
