#include <cstdio>
#include <algorithm>
#define L long long
#define P pair<L, int>
#define F first
#define S second
using namespace std;
P a[100002];
int n = 0, chk[100002];
L t, ans = 0;
int main() {
    scanf("%lld", &t);
    while(scanf("%lld", &t) && t != 0) {
        a[n] = P(-t, n+1);
        chk[++n] = t;
    }
    sort(a, a+n);
    int nw = a[0].S;
    for(int i = 1; i < n; i++) {
        if(chk[ a[i].S ] == 0)      continue;
        if(nw > a[i].S){
            ans += chk[ a[i].S-1 ];
            chk[ a[i].S-1 ] = 0;
        } else {
            ans += chk[ a[i].S+1 ];
            chk[ a[i].S+1 ] = 0;
        }
        nw = a[i].S;
    }
    printf("%lld\n", ans);
    return 0;
}

