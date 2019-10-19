#include <iostream>
#include <vector>
#define N 300000
#define P pair<int, int>
#define F first
#define S second
using namespace std;
vector <P> g[N+2];
int n, m;
int d[N+2];
int s, e;
bool chk[N+2], isBug = false;
void dfs(int u) {
    bool isLoop = true;
    while(isLoop) {
        isLoop = false;
        for(P v : g[u]) {
            if(chk[v.S])        continue;
            if(d[v.F] == 1) {
                d[u] = 0;
                d[v.F] = 0;
                chk[v.S] = true;
                return;
            }
        }
        for(P v : g[u]) {
            if(chk[v.S])        continue;
            if(d[v.F] == -1) {
                d[u] = 0;
                chk[v.S] = true;
                return;
            }
        }
        for(P v : g[u]) {
            if(chk[v.S])        continue;
            if(d[v.F] == 0) {
                d[u] = 0;
                d[v.F] = 1;
                chk[v.S] = true;
                u = v.F;
                isLoop = true;
                break;
            }
        }
    }
    isBug = true;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> d[i];
    for(int i = 1; i <= m; i++) {
        cin >> s >> e;
        g[s].push_back( P(e, i) );
        g[e].push_back( P(s, i) );
    }
    for(int i = 1; i <= n; i++) {
        if(d[i] == 1)       dfs(i);
    }
    if(isBug) {
        cout << "-1\n";
        return 0;
    }
    int cnt = 0;
    for(int i = 1; i <= m; i++)
        if(chk[i])      cnt++;
    cout << cnt << '\n';
    for(int i = 1; i <= m; i++)
        if(chk[i])      cout << i << ' ';
    return 0;
}
