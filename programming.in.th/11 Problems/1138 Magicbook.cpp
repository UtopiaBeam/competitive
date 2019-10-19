#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#define N (int)1e5
using namespace std;

int st[20*N+2], x[N+2], a[N+2];
vector<int> idx;
map<int, int> mp;

void ud(int s, int e, int nw, int idx, int v) {
    if (s > e)      return;
    if (s == e) {
        st[nw] = v;
        return;
    }
    int m = (s+e)>>1;
    if (idx <= m)   ud(s, m, nw<<1, idx, v);
    else        ud(m+1, e, nw<<1|1, idx, v);
    st[nw] = max(st[nw<<1], st[nw<<1|1]);
}

int qr(int s, int e, int nw, int l, int r) {
    if (r < s || e < l || s > e)    return -1;
    if (l <= s && e <= r)   return st[nw];
    int m = (s+e)>>1;
    return max(qr(s, m, nw<<1, l, r),
            qr(m+1, e, nw<<1|1, l, r));
}

int main() {
    int n, k, s;
    scanf("%d %d %d", &n, &k, &s);
    idx.push_back(s);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", x+i, a+i);
        idx.push_back(x[i]);
        idx.push_back(x[i]-k);
        idx.push_back(x[i]+k);
    }

    sort(idx.begin(), idx.end());

    int sz = 0;
    for (int i = 0; i < idx.size(); i++) {
        if (!mp[idx[i]])    mp[idx[i]] = ++sz;
    }
    
    memset(st, -1, sizeof(st));
    ud(1, sz, 1, mp[s], 0);
    for (int i = 0; i < n; i++) {
        int nw = mp[x[i]], l = mp[x[i]-k], r = mp[x[i]+k];
        int mx = qr(1, sz, 1, l, r);
        if (mx >= 0)    ud(1, sz, 1, nw, a[i]+mx);
    }

    printf("%d\n", st[1]);
    return 0;
}