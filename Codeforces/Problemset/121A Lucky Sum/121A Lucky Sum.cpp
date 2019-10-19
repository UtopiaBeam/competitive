#include <cstdio>
#include <vector>
#include <algorithm>
#define L long long
#define N (L)(1e10)
using namespace std;
vector<L> v;
L l, r;
int main() {
    v.push_back(4);
    v.push_back(7);
    for(int i = 0; i < v.size(); i++) {
        if(10*v[i] + 4 < N)     v.push_back( 10*v[i] + 4 );
        if(10*v[i] + 7 < N)     v.push_back( 10*v[i] + 7 );
    }
    scanf("%I64d %I64d", &l, &r);
    int s = upper_bound(v.begin(), v.end(), l-1) - v.begin();
    L ans = 0;
    while(v[s] < r) {
        ans += v[s] *(v[s]-l+1);
        l = v[s++]+1;
    }
    ans += v[s] * (r-l+1);
    printf("%I64d\n", ans);
    return 0;
}
