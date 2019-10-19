#include <cstdio>
#include <algorithm>
#define L long long
using namespace std;
int n;
L x, sum = 0, mx = 0;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%I64d", &x);
        sum += x;
        mx = max(mx, x);
    }
    printf("%I64d\n", max(mx, sum/(n-1) + (sum%(n-1) > 0)) );
    return 0;
}
