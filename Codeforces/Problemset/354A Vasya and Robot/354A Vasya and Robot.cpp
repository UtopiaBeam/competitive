#include <iostream>
#include <algorithm>
#define INF 1<<30
using namespace std;
int n, l, r, ql, qr;
int a[100002];
int main() {
    cin >> n >> l >> r >> ql >> qr;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int mn = INF;
    for(int i = 0; i <= n; i++) {
        if(i < n-i) {
            int d = max(0, n-2*i-1);
            mn = min(mn, a[i]*l + (a[n]-a[i])*r + d*qr);
        }
        else {
            int d = max(0, 2*i-n-1);
            mn = min(mn, a[i]*l + (a[n]-a[i])*r + d*ql);
        }
    }
    cout << mn;
    return 0;
}
