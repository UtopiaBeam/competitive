#include <cstdio>
#include <vector>
#include <algorithm>
#define L long long
#define P (L)98765431
#define N 2002
#define SZ 30
using namespace std;

char a[N], b[N];
L pw[SZ] = {1};
vector<L> v;

int main() {
    for (int i = 1; i < SZ; i++)
        pw[i] = P * pw[i-1];

    scanf(" %s %s", a, b);

    for (int i = 0; a[i]; i++) {
        L hs = 0;
        for (int j = i; a[j]; j++) {
            hs += pw[a[j]-'A'];
            v.push_back(hs);
        }
    }

    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; b[i]; i++) {
        L hs = 0;
        for (int j = i; b[j]; j++) {
            hs += pw[b[j]-'A'];
            if (binary_search(v.begin(), v.end(), hs))
                ans = max(ans, j-i+1);
        }
    }
    printf("%d\n", ans);
    return 0;
}