#include <cstdio>
int q;
int n, k;
int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%d %d", &n, &k);
        n -= k - 1;
        bool isAWin = true;
        for(int i = 0; 1<<i <= n; i++) {
            if(1<<i == n)       isAWin = false;
        }
        if(isAWin)      printf("A\n");
        else            printf("B\n");
    }
    return 0;
}
