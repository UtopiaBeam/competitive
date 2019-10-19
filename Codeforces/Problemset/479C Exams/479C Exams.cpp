#include <cstdio>
#include <algorithm>
#define P pair<int, int>
#define F first
#define S second
using namespace std;
int n, mx;
P a[5002];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &a[i].F, &a[i].S);
    sort(a, a+n);
    int mn = -1;
    for(int i = 0; i < n; i++) {
        if(mn <= a[i].S)        mn = a[i].S;
        else                    mn = a[i].F;
    }
    printf("%d\n",  mn);
    return 0;
}
