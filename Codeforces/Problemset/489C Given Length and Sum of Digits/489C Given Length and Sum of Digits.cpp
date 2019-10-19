#include <iostream>
using namespace std;
int n, s, sum;
string mn, mx;
bool isAble(int n, int s) {
    return (n >= 0) && (s <= 9*n) && (s >= 0);
}
int main() {
    cin >> n >> s;
    if( (n > 1 && s == 0) || (s > 9*n) ) {
        cout << "-1 -1\n";
        return 0;
    }
    sum = s;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 10; j++)
            if( (i > 1 || j > 0 || (n == 1 && j == 0) ) && isAble(n - i, sum - j) ) {
                mn += j + '0';
                sum -= j;
                break;
            }
    sum = s;
    for(int i = 1; i <= n; i++)
        for(int j = 9; j >= 0; j--)
            if( (i > 1 || j > 0 || (n == 1 && j == 0) ) && isAble(n - i, sum - j) ) {
                mx += j + '0';
                sum -= j;
                break;
            }
    cout << mn << ' ' <<  mx << '\n';
    return 0;
}
