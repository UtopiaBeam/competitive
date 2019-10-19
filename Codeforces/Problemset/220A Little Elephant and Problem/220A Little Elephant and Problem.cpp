#include <cstdio>
#include <algorithm>
#define N 100000
int n, a[N+2], b[N+2];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a+i);
        b[i] = a[i];
    }
    std::sort(b, b+n);
    int cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += (a[i] != b[i]);
    if(cnt == 0 || cnt == 2)
        printf("YES\n");
    else        printf("NO\n");
    return 0;
}
