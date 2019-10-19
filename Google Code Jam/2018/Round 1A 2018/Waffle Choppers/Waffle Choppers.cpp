#include <cstdio>
#define N 100
void each(int t) {
    int r, c, h, v;
    char a[N+2][N+2];
    scanf("%d %d %d %d", &r, &c, &h, &v);
    int cnt = 0;
    for(int i = 0; i < r; i++) {
        scanf(" %s", a[i]);
        for(int j = 0; j < c; j++)
            cnt += (a[i][j] == '@');
    }

    printf("Case #%d: %s\n", t, "test");
}
int main() {
    int q, r, c, h, v;
    scanf("%d", &q);
    for(int t = 1; t <= q; t++)
        each(t);
    return 0;
}
