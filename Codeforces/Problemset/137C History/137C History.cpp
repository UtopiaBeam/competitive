#include <cstdio>
#include <algorithm>
#define P pair<int, int>
#define F first
#define S second
using namespace std;
int n;
P a[100002];
int mx = 0, cnt = 0;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &a[i].F, &a[i].S);
    sort(a, a+n);
    mx = a[0].S;
    for(int i = 1; i < n; i++) {
        if(a[i].S < mx)     cnt++;
        mx = max(mx, a[i].S);
    }
    printf("%d\n", cnt);
    return 0;
}
