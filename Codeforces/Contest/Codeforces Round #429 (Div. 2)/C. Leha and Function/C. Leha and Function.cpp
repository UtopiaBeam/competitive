#include <iostream>
#include <algorithm>
#define N 200000
#define P pair<int, int>
#define F first
#define S second
using namespace std;
int n;
int a[N+2], ans[N+2];
P b[N+2];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = -a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i].F;
        b[i].S = i;
    }
    sort(a, a+n);       sort(b, b+n);
    for(int i = 0; i < n; i++)
        ans[ b[i].S ] = -a[i];
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    return 0;
}
