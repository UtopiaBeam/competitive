#include <cstdio>
#include <queue>
#include <vector>
#define P pair<int, int>
#define F first
#define S second
using namespace std;
queue<P> q;
vector<P> g[300002];
vector<int> ans;
int n, k, d;
int s, e, p;
int a[300002];
bool vs[300002], cut[300002];
int main() {
    scanf("%d %d %d", &n, &k, &d);
    for(int i = 0; i < k; i++) {
        scanf("%d", a+i);
        q.push( P(a[i], 0) );
    }
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &s, &e);
        g[s].push_back( P(e, i) );
        g[e].push_back( P(s, i) );
    }
    while( !q.empty() ) {
        s = q.front().F;
        p = q.front().S;
        q.pop();
        if(vs[s])       continue;
        vs[s] = true;
        for(P e : g[s]) {
            if(p == e.F)    continue;
            if(vs[e.F])     cut[e.S] = true;
            else        q.push( P(e.F, s) );
        }
    }
    for(int i = 1; i < n; i++)
        if( cut[i] )        ans.push_back(i);
    printf("%d\n", ans.size());
    for(int x : ans)
        printf("%d ", x);
    return 0;
}
