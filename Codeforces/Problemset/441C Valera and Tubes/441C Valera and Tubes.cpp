#include <cstdio>
int r, c, k;
int x = 1, y = 1;
int main() {
    scanf("%d %d %d", &r, &c, &k);
    int l = (r*c) / k;
    for(int t = 1; t <= k; t++) {
        if(t == k)      l += (r*c) % k;
        printf("%d ", l);
        for(int i = 0; i < l; i++) {
            printf("%d %d ", x, y);
            if(x & 1) {
                y++;
                if(y > c)       x++, y = c;
            }
            else {
                y--;
                if(y < 1)       x++, y = 1;
            }
        }
        printf("\n");
    }
    return 0;
}
