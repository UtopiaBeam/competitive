#include <cstdio>
int n, a[1000002];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        a[i] += a[i-1];
    }
    int cnt = 0;
    for(int i = 1; i < n; i++)
        cnt += (a[i] == a[n] - a[i]);
    printf("%d\n", cnt);
    return 0;
}
