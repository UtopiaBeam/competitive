#include <cstdio>
#define L long long
int n, d;
int a[100002];
L ans = 0, t;
int main() {
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    int l = 0;
    for(int i = 0; i < n; i++) {
        while(l < i && a[i]-a[l] > d)
            l++;
        t = i - l;
        ans += (t * (t-1)) / 2;
    }
    printf("%I64d\n", ans);
    return 0;
}
