#include <cstdio>
#include <queue>
#define L long long
#define P pair<int,int>
#define PP pair<L,P>
#define F first
#define S second
using namespace std;
priority_queue<PP> q;
int n, m, s, e;
L w, ans = 0;
int r[1000002];
int fd(int x) {
    if(x == r[x])   return x;
    return r[x] = fd(r[x]);
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        r[i] = i;
    while(m--) {
        scanf("%d %d %lld", &s, &e, &w);
        q.push( PP(w, P(s, e)) );
    }
    while(!q.empty()) {
        w = q.top().F;
        s = q.top().S.F;
        e = q.top().S.S;
        q.pop();
        int rs = fd(s), re = fd(e);
        if(rs == re)    continue;
        r[rs] = re;
        ans += w-1;
    }
    printf("%lld\n", ans);
    return 0;
}
