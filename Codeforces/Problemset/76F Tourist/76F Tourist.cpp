#include <cstdio>
#include <vector>
#include <algorithm>
#define L long long
#define P pair<L, L>
#define F first
#define S second
using namespace std;
vector<P> v1, v2;
vector<L> LIS;
P a[100002];
int n, mx = 0;
L v, x[100002], t[100002];
int solve(vector<P> v) {
    LIS.clear();
    for(int i = 0; i < v.size(); i++) {
        int idx = upper_bound(LIS.begin(), LIS.end(), v[i].S) - LIS.begin();
        if(idx >= LIS.size())       LIS.push_back(v[i].S);
        else        LIS[idx] = v[i].S;
    }
    return LIS.size();
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%I64d %I64d", x+i, t+i);
    scanf("%I64d", &v);

    for(int i = 0; i < n; i++) {
        L p = x[i] + v*t[i];
        L q = -x[i] + v*t[i];
        v1.push_back( P(p, q) );
        if(p >= 0 && q >= 0)    v2.push_back( P(p, q) );
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    printf("%d %d\n", solve(v2), solve(v1));
    return 0;
}
