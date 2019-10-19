#include <cstdio>
#include <algorithm>
int c, v0, v1, a, l;
int ans = 0;
int main() {
    scanf("%d %d %d %d %d", &c, &v0, &v1, &a, &l);
    int nw = 0;
    while(nw < c) {
        nw += std::min(v0, v1) - l * (ans > 0);
        v0 += a;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
