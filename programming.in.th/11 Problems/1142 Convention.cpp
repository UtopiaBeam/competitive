#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#define P pair<int, int>
#define F first
#define S second
#define N (int)1e5
#define INF 1<<30
using namespace std;

P a[N+2];
int n, k, l, r;
int st[6*N+2], lz[6*N+2];
vector<int> v;
map<int, int> mp;

void ud(int s, int e, int nw) {
    if (lz[nw]) {
        st[nw] += lz[nw];
        if (s != e) {
            lz[nw<<1] += lz[nw];
            lz[nw<<1|1] += lz[nw];
        }
        lz[nw] = 0;
    }
    if (e < l || r < s || s > e)    return;
    if (l <= s && e <= r) {
        st[nw]++;
        if (s != e) {
            lz[nw<<1]++;    lz[nw<<1|1]++;
        }
        return;
    }
    int m = (s+e)>>1;
    ud(s, m, nw<<1);    ud(m+1, e, nw<<1|1);
    st[nw] = max(st[nw<<1], st[nw<<1|1]);
}

int qr(int s, int e, int nw) {
    if (lz[nw]) {
        st[nw] += lz[nw];
        if (s != e) {
            lz[nw<<1] += lz[nw];
            lz[nw<<1|1] += lz[nw];
        }
        lz[nw] = 0;
    }
    if (e < l || r < s || s > e)    return -INF;
    if (l <= s && e <= r)   return st[nw];
    int m = (s+e)>>1;
    return max( qr(s, m, nw<<1), qr(m+1, e, nw<<1|1) );
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].F, &a[i].S);
        v.push_back(a[i].F);
        v.push_back(a[i].S);
    }

    sort(v.begin(), v.end());
    int ord = 0;
    for (int i = 0; i < v.size(); i++)
        if ( !mp[v[i]] )
            mp[v[i]] = ++ord;

    for (int i = 0; i < n; i++) {
        l = mp[ a[i].F ], r = mp[ a[i].S ];
        if (qr(1, mp.size(), 1) < k) {
            printf("yes\n");
            ud(1, mp.size(), 1);
        } else {
            printf("no\n");
        }
    }

    return 0;
}