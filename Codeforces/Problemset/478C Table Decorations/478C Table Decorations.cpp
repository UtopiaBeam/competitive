#include <cstdio>
#include <algorithm>
using namespace std;
long long a[5];
int main() {
    for(int i = 0; i < 3; i++)
        scanf("%I64d", a+i);
    sort(a, a+3);
    if(a[0] + a[1] > a[2]/2)
        printf("%I64d\n", (a[0] + a[1] + a[2])/3);
    else        printf("%I64d\n", a[0] + a[1]);
    return 0;
}
