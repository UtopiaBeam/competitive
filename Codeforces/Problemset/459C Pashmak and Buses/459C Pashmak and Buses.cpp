#include <cstdio>
#define L long long
int n, k, d;
int ans[1002][1002];
int main() {
    scanf("%d %d %d", &n, &k, &d);
    L tmp = 1;
    bool isPos = false;
    for(int i = 0; i < d; i++) {
        tmp *= k;
        if(n <= tmp) {
            isPos = true;
            break;
        }
    }
    if( !isPos ) {
        printf("-1\n");
        return 0;
    }
    for(int i = 0; i < n; i++) {
        int t = i;
        for(int j = 0; j < d; j++) {
            ans[j][i] = t % k;
            t /= k;
        }
    }
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", ans[i][j]+1);
        printf("\n");
    }
    return 0;
}
