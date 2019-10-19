#include <cstdio>
#define N 1000

int qs[N+2][N+2];
int n, k;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &qs[i][j]);
            qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
        }
}