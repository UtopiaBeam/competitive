#include <cstdio>
#include <cstring>
#define MOD 2553
#define L long long
#define N 10

int mat[N][N] = {{0, 1, 0, 0},
                 {0, 0, 1, 0},
                 {0, 0, 0, 1}},
    tmp[N][N], res[N][N];
int cn[N];

void multiply(int a[N][N], int b[N][N]) {
    int mul[N][N];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                mul[i][j] += a[i][k] * b[k][j];
                mul[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            a[i][j] = mul[i][j];
}

int main() {
    for (int i = 0; i < 4; i++)
        scanf("%d", cn+i);
    for (int i = 3; i >= 0; i--)
        scanf("%d", &mat[3][i]);

    int q;
    scanf("%d", &q);
    while (q--) {
        L n;
        scanf("%lld", &n);
        if (n <= 4) {
            printf("%d\n", cn[n-1] % MOD);
            continue;
        }
        memset(res, 0, sizeof(res));
        for (int i = 0; i < 4; i++) {
            res[i][i] = 1;
            for (int j = 0; j < 4; j++)
                tmp[i][j] = mat[i][j];
        }
        n -= 4;
        while (n > 0) {
            if (n & 1)      multiply(res, tmp);
            multiply(tmp, tmp);
            n >>= 1;
        }

        int ans = 0;
        for (int i = 0; i < 4; i++) {
            ans += res[3][i] * cn[i];
            ans %= MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}