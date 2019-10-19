#include <cstdio>
#define L long long
L n;
int main() {
    scanf("%I64d", &n);
    if(n == 1)          printf("1\n");
    else if(n == 2)     printf("2\n");
    else if(n % 2)      printf("%I64d\n", (n-2) * (n-1) * n);
    else if(n % 3)      printf("%I64d\n", (n-3) * (n-1) * n);
    else                printf("%I64d\n", (n-3) * (n-2) * (n-1));
    return 0;
}
