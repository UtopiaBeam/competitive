#include <cstdio>
#include <algorithm>
#define N 100000
#define P pair<int, int>
#define F first
#define S second
using namespace std;
int n, cnt = 0;
P a[N+2];
bool cmp(P x, P y) {
    return abs(x.F) + abs(x.S) < abs(y.F) + abs(y.S);
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].F, &a[i].S);
        if(a[i].F != 0)       cnt += 2;
        if(a[i].S != 0)       cnt += 2;
        cnt += 2;
    }
    sort(a, a+n, cmp);
    printf("%d\n", cnt);
    for(int i = 0; i < n; i++) {
        if(a[i].F > 0)        printf("1 %d R\n", a[i].F);
        if(a[i].F < 0)        printf("1 %d L\n", -a[i].F);
        if(a[i].S > 0)        printf("1 %d U\n", a[i].S);
        if(a[i].S < 0)        printf("1 %d D\n", -a[i].S);
        printf("2\n");
        if(a[i].F > 0)        printf("1 %d L\n", a[i].F);
        if(a[i].F < 0)        printf("1 %d R\n", -a[i].F);
        if(a[i].S > 0)        printf("1 %d D\n", a[i].S);
        if(a[i].S < 0)        printf("1 %d U\n", -a[i].S);
        printf("3\n");
    }
    return 0;
}
