#include <cstdio>
#include <algorithm>
#define P pair<int, int>
#define F first
#define S second
using namespace std;
int n;
P a[100002];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i].F);
        a[i].S = i+1;
    }
    sort(a, a+n);
    printf("%d\n", (n+1)/2);
    for(int i = 0; i < n; i += 2)
        printf("%d ", a[i].S);
    printf("\n%d\n", n/2);
    for(int i = 1; i < n; i += 2)
        printf("%d ", a[i].S);
    return 0;
}
