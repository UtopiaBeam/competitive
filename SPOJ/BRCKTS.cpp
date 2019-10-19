#include <cstdio>
#include <utility>
#define P pair<int, int>
#define F first
#define S second
using namespace std;
int n, m, x;
P st[90002];
char a[30002];
void bd(int s, int e, int in) {
    if (s > e)
        return;
    if (s == e) {
        if (a[s] == '(')
            st[in] = P(1, 0);
        else
            st[in] = P(0, 1);
        return;
    }
    int m = (s + e) / 2;
    bd(s, m, 2 * in);
    bd(m + 1, e, 2 * in + 1);
    st[in] = P(st[2 * in].F + st[2 * in + 1].F, st[2 * in].S + st[2 * in + 1].S);
    P l = st[2 * in], r = st[2 * in + 1];
    if (l.F <= r.S)
        st[in] = P(r.F, l.S + r.S - l.F);
    else
        st[in] = P(l.F + r.F - r.S, l.S);
}
void ud(int s, int e, int in) {
    if (s > e)
        return;
    if (s == e) {
        if (st[in] == P(1, 0))
            st[in] = P(0, 1);
        else
            st[in] = P(1, 0);
        return;
    }
    int m = (s + e) / 2;
    if (m >= x)
        ud(s, m, 2 * in);
    else
        ud(m + 1, e, 2 * in + 1);
    P l = st[2 * in], r = st[2 * in + 1];
    if (l.F <= r.S)
        st[in] = P(r.F, l.S + r.S - l.F);
    else
        st[in] = P(l.F + r.F - r.S, l.S);
}
int main() {
    for (int t = 1; t <= 10; t++) {
        printf("Test %d:\n", t);
        scanf("%d %s", &n, a+1);
        bd(1, n, 1);
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &x);
            if (x)      ud(1, n, 1);
            else
            {
                if (st[1].F == 0 && st[1].S == 0)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
    return 0;
}
