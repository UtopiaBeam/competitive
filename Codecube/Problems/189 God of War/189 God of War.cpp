#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define P pair<int, int>
#define PP pair<int, P>
#define F first
#define S second
#define N (int)1e5
#define INF 1<<30
using namespace std;

vector<P> g[N+2];
priority_queue<PP> hp;
int dsc[N+2], dsk[N+2];
int n, m, sum = 0;
int sc, sk, ans = 0;

void SSSP(int *d, int sc) {
	for (int i = 0; i < n; i++)
		d[i] = INF;
	hp.push( PP(0, P(0, sc)) );
	while (!hp.empty()) {
		int ds = -hp.top().F;
		int nw = hp.top().S.F;
		int u = hp.top().S.S;
		hp.pop();

		if (d[u] <= ds)	 continue;
		d[u] = ds;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].F, w = g[u][i].S;
			if (w + ds < d[v])
				hp.push( PP(-w-ds, P(max(nw, w), v)) );
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> sc >> sk;
	while(m--) {
		int s, e, w;
		cin >> s >> e >> w;
		sum += w;
		g[s].push_back( P(e, w) );
		g[e].push_back( P(s, w) );
	}

	SSSP(dsc, sc);      SSSP(dsk, sk);

	for (int u = 0; u < n; u++) {
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].F, w = g[u][i].S;
            ans = max(ans, sum - min(dsc[u]+dsk[v], dsc[v]+dsk[u]));
        }
	}

	cout << ans << '\n';

	return 0;
}
