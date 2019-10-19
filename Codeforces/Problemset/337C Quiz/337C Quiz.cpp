#include <iostream>
#include <algorithm>
#define L long long
#define MOD (L)(1e9 + 9)
using namespace std;
L n, m, k;
L f(L a, L b) {
    L res = 1;
    while(b) {
        if(b % 2)   res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res % MOD;
}
int main() {
    cin >> n >> m >> k;
    L x = m - (n/k) * (k-1) - (n%k);
    if(x < 0)       x = 0;
    cout << (((f(2, x+1) - 2) * k + MOD) % MOD + (m - x*k + MOD) % MOD) % MOD;
    return 0;
}
