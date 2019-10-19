#include <cstdio>
#include <vector>
#include <algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n, k, ans = 0;
P a[200002];
vector<P> vf, vs;
bool cmp(P x, P y) {
    return (x.F - x.S) < (y.F - y.S);
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i].F);
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i].S);
        if(a[i].F <= a[i].S)
            vf.push_back(a[i]);
        else    vs.push_back(a[i]);
    }
    sort(vf.begin(), vf.end());
    sort(vs.begin(), vs.end(), cmp);
    for(int i = 0; i < vf.size(); i++) {
        k--;
        ans += vf[i].F;
    }
    for(int i = 0; i < vs.size(); i++) {
        if(k > 0) {
            ans += vs[i].F;
            k--;
        }
        else    ans += vs[i].S;
    }
    printf("%d\n",ans);
    return 0;
}
