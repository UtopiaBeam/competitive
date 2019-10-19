#include <cstdio>
#define L long long
#define N 500000
int n;
L a[N+2], sum = 0, s = 0;
L cnt[N+2], ans;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%I64d", a+i);
        sum += a[i];
    }
    if(n < 3 || sum % 3) {
        printf("0\n");
        return 0;
    }
    sum /= 3;
    for(int i = n-1; i >= 0; i--) {
        s += a[i];
        cnt[i] = cnt[i+1] + (s == sum);
    }
    s = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];
        if(s == sum)    ans += cnt[i+2];
    }
    printf("%I64d\n", ans);
    return 0;
}
