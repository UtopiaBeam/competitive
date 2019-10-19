#include <cstdio>
int n, k;
int main() {
    scanf("%d %d", &n, &k);
    if(n/2 > k || (n == 1 && k > 0) ){
        printf("-1\n");
        return 0;
    }
    if(n == 1) {
        printf("1\n");
        return 0;
    }
    k -= n/2 - 1;
    printf("%d %d", k, 2*k);
    n -= 2;
    int nw = 2;
    for(int i = 1; nw <= n; i += 2) {
        if(i == k || i == 2*k || i+1 == k || i+1 == 2*k)
            continue;
        else {
            printf(" %d %d", i, i+1);
            nw += 2;
        }
    }
    if(n % 2 == 1)      printf(" 1000000000");
    return 0;
}
