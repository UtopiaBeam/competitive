#include <iostream>
#include <cmath>
using namespace std;
int n, t;
long double ans;
int main() {
    cin >> n;
    while(n--) {
        cin >> t;
        ans = 1;
        while(t--) {
            ans *= 2;
        }
        cout << ans << '\n';
    }
    return 0;
}
