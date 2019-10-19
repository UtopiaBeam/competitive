#include <cstdio>
int n, m, k;
int s, e;
int cnt = 0;
int a[300002], c[300002];
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int tmp = 0;
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", a+j);
            if(c[a[j]] > 0)         tmp++;
        }
        for(int j = 0; j < k; j++) {
            if(c[a[j]] == 0)        c[a[j]] = ++tmp;
            if(cnt < tmp)       cnt = tmp;
        }
    }
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &s, &e);
    }
    printf("%d\n", cnt);
    for(int i = 1; i <= m; i++)
        printf("%d ", c[i]);
    return 0;
}
