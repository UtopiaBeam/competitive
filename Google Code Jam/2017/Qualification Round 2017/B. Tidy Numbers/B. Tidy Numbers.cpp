#include <cstdio>
#include <vector>
#include <algorithm>
#define L long long
#define LIM (L)1e18
using namespace std;
L n;
int q;
vector <L> v;
void fileIO() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
}
void process() {
    for(int i = 1; i < 10; i++)
        v.push_back(i);
    for (int i = 0; i < v.size(); i++) {
        for (int j = v[i]%10; j < 10 && v.back() <= LIM; j++) {
            v.push_back( 10*v[i] + j );
        }
    }
}
L bs(int s, int e) {
    if(s == e)      return v[s];
    int m = (s+e+1)/2;
    if(v[m] > n)    return bs(s, m-1);
    return bs(m, e);
}
int main() {
    fileIO();
    process();
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        scanf("%lld", &n);
        printf("Case #%d: %lld\n", i, bs(0, v.size()-1));
    }
    return 0;
}
