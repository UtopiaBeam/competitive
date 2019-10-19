#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define N (int)1e5
using namespace std;

unordered_map<int, vector<int>> hs;
int n, q;
int t, l, r, v;

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        hs[t].push_back(i);
    }

    while(q--) {
        scanf("%d %d %d", &l, &r, &v);
        vector<int> ls = hs[v];
        printf("%d\n", upper_bound(ls.begin(), ls.end(), r) - lower_bound(ls.begin(), ls.end(), l));
    }

    return 0;
}
