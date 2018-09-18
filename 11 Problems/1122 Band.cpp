#include <cstdio>
#include <vector>
#define P pair<int, int>
#define F first
#define S second
#define N 1000
#define L long long
using namespace std;

int n, m;
vector<P> edges;
int g[N+2][N+2];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        g[s][e] = g[e][s] = 1;
        edges.push_back( P(s, e) );
    }
    
    L ans = 0;
    // 5-or-more-edge case
    for (int i = 0; i < edges.size(); i++) {
        L cnt = 0;
        P nw = edges[i];
        for (int u = 1; u <= n; u++)
            if (g[u][nw.F] && g[u][nw.S])
                cnt++;
        ans += (cnt*(cnt-1)) / 2;
    }
    // 6-edge case
    L cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        for (int j = i+1; j < edges.size(); j++) {
            P x = edges[i], y = edges[j];
            if (g[x.F][y.F] && g[x.F][y.S] && g[x.S][y.F] && g[x.S][y.S])
                cnt++;
        }
    }
    printf("%lld\n", ans-cnt/3*5);
    return 0;
}