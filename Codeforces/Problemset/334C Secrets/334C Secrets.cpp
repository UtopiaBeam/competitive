#include <cstdio>
#define L long long
L n, b = 3;
L ceil() {
    if(n % b)     return n/b + 1;
    return n/b;
}
int main() {
    scanf("%I64d", &n);
    while(n % b == 0)
        b *= 3;
    printf("%I64d\n", ceil());
    return 0;
}
