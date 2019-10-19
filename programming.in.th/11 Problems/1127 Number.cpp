#include <cstdio>

int n, cs[12];
char ans[102];

int main() {
    int mn = 1<<30, val;
    scanf("%d", &n);
    for (int i = 1; i < 10; i++) {
        scanf("%d", cs+i);
        if (mn >= cs[i]) {
            mn = cs[i];
            val = i;
        }
    }
    int dig = n / mn;
    int rm = n - mn * dig;
    for (int i = 0; i < dig; i++) {
        for (int j = 9; j >= val; j--) {
            if (rm >= cs[j] - mn) {
                rm -= cs[j] - mn;
                ans[i] = '0' + j;
                break;
            }
        }
    }
    printf("%s\n", ans);
    return 0;
}