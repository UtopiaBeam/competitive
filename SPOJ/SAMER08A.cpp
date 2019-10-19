#include <cstdio>
#include <queue>
#include <vector>
#define INF 1<<30
#define P pair<int, int>
#define F first
#define S second
using namespace std;
priority_queue<P> q;
vector<int> p[502];
int g[502][502], d[502];
int n, m;
int s, e, w;
int u, v;
void dijks() {
    q.push( P(0, u) );
    while( !q.empty() ) {
        w = -q.top().F;
        s = q.top().S;
        q.pop();
        if(d[s] <= w)       continue;
        d[s] = w;
        for(int e = 0; e < n; e++) {
            if(d[s] + g[s][e] < d[e])
                q.push( P(-d[s] - g[s][e], e) );
        }
    }
}
void findParent() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(d[i] + g[i][j] == d[j])
                p[j].push_back(i);
}
void del(int s) {
    for(int i = 0; i < p[s].size(); i++) {
        e = p[s][i];
        g[e][s] = INF;
        del(e);
    }
}
int main() {
    while(scanf("%d %d", &n, &m) && n && m) {
        scanf("%d %d", &u, &v);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                g[i][j] = INF;
            p[i].clear();
            d[i] = INF;
        }
        while(m--) {
            scanf("%d %d %d", &s, &e, &w);
            g[s][e] = w;
        }
        dijks();
        findParent();
        del(v);
        for(int i = 0; i < n; i++) {
            p[i].clear();
            d[i] = INF;
        }
        dijks();
        if(d[v] == INF)         printf("-1\n");
        else        printf("%d\n", d[v]);
    }
    return 0;
}
