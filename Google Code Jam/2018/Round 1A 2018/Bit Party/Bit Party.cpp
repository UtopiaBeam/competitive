#include <cstdio>
#include <algorithm>
#include <vector>
#define N 1000
using namespace std;
void each(int t) {
    int r, b, c;
    struct S {
        int m, s, p;
    }a[N+2];
    scanf("%d %d %d", &r, &b, &c);
    for(int i = 0; i < c; i++)
        scanf("%d %d %d", &a[i].m, &a[i].s, &a[i].p);
    sort(a, a+c, [](S x, S y) -> bool {
            return x.s < y.s;
        });
}
int main() {
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
        each(i);
}
