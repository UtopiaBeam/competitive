#include <cstdio>
#include <vector>
#include <algorithm>
#define L long long
#define INF_MIN (L)(-1)<<60
using namespace std;
L a[200002], sum[200002], mxsum[200002];
vector<int> g[200002];
bool isPos = false, chk[200002];
L mx = INF_MIN;
int n, s ,e;
void dfs(int u) {
    if(chk[u])      return;
    chk[u] = true;
    vector<L> t;
    int cnt = 0;
    sum[u] = a[u];
    for(int v : g[u]) {
        if(chk[v])      continue;
        dfs(v);     cnt++;
        sum[u] += sum[v];
        t.push_back(-mxsum[v]);
        mxsum[u] = max(mxsum[u], mxsum[v]);
    }
    if(cnt > 1)     isPos = true;
    mxsum[u] = max(mxsum[u], sum[u]);
    if(t.size() < 2)    return;
    sort(t.begin(), t.end());
    mx = max(mx, -t[0]-t[1]);
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%I64d", a+i);
        mxsum[i] = INF_MIN;
    }
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &s, &e);
        g[s].push_back(e);
        g[e].push_back(s);
    }
    dfs(1);
    if(isPos)       printf("%I64d\n", mx);
    else            printf("Impossible\n");
    return 0;
}
