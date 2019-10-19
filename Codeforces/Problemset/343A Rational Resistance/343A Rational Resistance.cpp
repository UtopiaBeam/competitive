#include <cstdio>
#define L long long
L a, b, cnt = 0;
void f(L x, L y) {
    cnt += x/y;
    if(y == 1)      return;
    x %= y;
    cnt++;
    f(y-x, x);
}
int main() {
    scanf("%I64d %I64d", &a, &b);
    f(a, b);
    printf("%I64d\n", cnt);
    return 0;
}
