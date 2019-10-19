#include <cstdio>
#define N 100000
int n, m;
int a[N+2], l[N+2], r[N+2];
int x, y;
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", a+i);
    l[1] = 1;
    for(int i = 2; i <= n; i++)
        if(a[i-1] >= a[i])      l[i] = l[ l[i-1] ];
        else            l[i] = i;
    r[n] = n;
    for(int i = n-1; i > 0; i--)
        if(a[i+1] >= a[i])      r[i] = r[ r[i+1] ];
        else            r[i] = i;
    while(m--) {
        scanf("%d %d", &x, &y);
        if(r[x] >= l[y])
            printf("Yes\n");
        else        printf("No\n");
    }
    return 0;
}
