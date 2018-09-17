#include <cstdio>
#include <cmath>
int n;
int main() {
    scanf("%d", &n);
    if(n == 1)              printf("2.000000\n");
    else if(n % 2 == 0)     printf("%lf\n", (double)n);
    else if(n == 3)         printf("%lf\n", 2 + sqrt(3));
    else                    printf("%lf\n", n - 3 + 2 * sqrt(3));
    return 0;
}
