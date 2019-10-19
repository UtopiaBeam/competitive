#include <iostream>
#include <vector>
#define N 10000
#define P pair<int, int>
#define F first
#define S second
using namespace std;
vector<P> g[N+2];
int t, n, s, e, w[N+2];
int cnt = 0, sz[N+2], chn[N+2];
string str;

void dfs(int u, int pu) {
    for(P v : g[u])
        if(v.F != pu) {
            dfs(v.F, u);
            sz[u] += sz[v.F];
        }
    sz[u]++;
}

void HLD(int u, int pu) {

}

void solve() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> s >> e >> w[i];
        g[s].push_back( P(e, i) );
        g[e].push_back( P(s, i) );
    }
    while(cin >> str && str != "DONE") {
        cin >> s >> e;
        if(str == "CHANGE") {
            ;
        }
        else {
            ;
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
