#include <cstdio>
#include <cstring>
#define L long long
#define N 1000
using namespace std;

int g[N+2][N+2];
int n, m;

int main() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            g[i][j] = 1;
        g[i][i] = 0;
    }

    scanf("%d %d", &n, &m);
    while (m--) {
        int s, e;
        scanf("%d %d", &s, &e);
        g[s][e] = g[e][s] = 0;
    }
    return 0;
}