#include <cstdio>
#include <queue>
#define P pair<int, int>
#define PP pair<int, P>
#define F first
#define S second
using namespace std;
priority_queue <PP> hp;
int n, x[102], y[102];
int r[102];
int ans = 0;
int fr(int x) {
    if(x == r[x])       return x;
    return r[x] = fr(r[x]);
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        r[i] = i;
        scanf("%d %d", x+i, y+i);
        for(int j = 0; j < i; j++)
            if(x[i] == x[j] || y[i] == y[j])
                hp.push( PP(0, P(i, j)) );
            else        hp.push( PP(-1, P(i, j)) );
    }
    while( !hp.empty() ) {
        int w = hp.top().F;
        int u = hp.top().S.F, v = hp.top().S.S;
        hp.pop();
        int ru = fr(u), rv = fr(v);
        if(ru == rv)        continue;
        r[ru] = rv;
        ans -= w;
    }
    printf("%d\n", ans);
    return 0;
}
