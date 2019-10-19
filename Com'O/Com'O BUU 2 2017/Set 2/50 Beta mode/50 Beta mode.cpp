#include <cstdio>
#include <algorithm>
using namespace std;
int dp[2][10002];
int mx = 0, e;
char a[10002], b[10002];
int main() {
    scanf(" %s %s", a, b);
    for(int i = 0; a[i]; i++)
        for(int j = 0; b[j]; j++) {
            if(a[i] == b[j]) {
                dp[(i+1)%2][j+1] = dp[i%2][j]+1;
                if(dp[(i+1)%2][j+1] > mx) {
                    mx = dp[(i+1)%2][j+1];
                    e = i;
                }
            }
            else    dp[(i+1)%2][j+1] = 0;
        }
    for(int i = e-mx+1; i <= e; i++)
        printf("%c", a[i]);
    return 0;
}
