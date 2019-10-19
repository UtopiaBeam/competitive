#include <cstdio>
#include <queue>
#define P pair<int,int>
#define PP pair<double,P>
#define F first
#define S second
using namespace std;
priority_queue<PP> q;
int n, m, s, e, rs, re;
int r[1002];
double w, ans = 0;
int fd(int u) {
    if(u == r[u])   return u;
    return r[u] = fd(r[u]);
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        r[i] = i;
    while(m--) {
        scanf("%d %d %lf", &s, &e, &w);
        q.push( PP(-w, P(s, e)) );
    }
    while(!q.empty()) {
        w = -q.top().F;
        s = q.top().S.F;
        e = q.top().S.S;
        q.pop();
        rs = fd(s), re = fd(e);
        if(rs != re)    ans += w;
        r[rs] = re;
    }
    printf("%.3lf\n", ans);
    return 0;
}
