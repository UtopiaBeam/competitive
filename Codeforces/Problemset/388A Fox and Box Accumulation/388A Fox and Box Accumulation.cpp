#include <cstdio>
#include <algorithm>
int n, a[102];
bool chk[102];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    std::sort(a, a+n);
    int cnt = 0, ans = 0;
    while(cnt < n) {
        int mn = 0;
        for(int i = 0; i < n; i++)
            if( !chk[i] && mn <= a[i] ) {
                chk[i] = true;
                mn++;       cnt++;
            }
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
