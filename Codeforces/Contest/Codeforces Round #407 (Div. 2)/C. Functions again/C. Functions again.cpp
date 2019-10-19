#include <cstdio>
#include <vector>
#include <algorithm>
#define L long long
using namespace std;
int n;
L a[100002], mx = (L)(-1)<<60;
vector<L> v;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%I64d", a+i);
    for(int i = 0; i < n-1; i++) {
        if(i&1)     v.push_back( -abs(a[i]-a[i+1]) );
        else        v.push_back( abs(a[i]-a[i+1]) );
    }
    L sum = 0;
    int s = -1;
    for(int i = 0; i < v.size(); i++) {
        if(s < 0) {
            if(i&1)     continue;
            s = i;
        }
        sum += v[i];
        if(sum <= 0) {
            s = -1;
            sum = 0;
        }
        mx = max(mx, sum);
    }
    sum = 0;
    s = -1;
    for(int i = 0; i < v.size(); i++) {
        if(s < 0) {
            if(!(i&1))     continue;
            s = i;
        }
        sum -= v[i];
        if(sum <= 0) {
            s = -1;
            sum = 0;
        }
        mx = max(mx, sum);
    }
    printf("%I64d\n", mx);
    return 0;
}
