#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
stack<char> st;
int dp[2002][2002];
int n, m;
char a[2002], b[2002];
int main() {
    scanf(" %s %s", a, b);
    n = strlen(a);
    m = strlen(b);
    for(int i = 0; a[i]; i++)
        for(int j = 0; b[j]; j++) {
            if(a[i] == b[j])    dp[i+1][j+1] = dp[i][j]+1;
            else    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    printf("%d\n", dp[n][m]);
    if(dp[n][m] == 0) {
        printf("No Roma word\n");
        return 0;
    }
    while(n > 0 && m > 0) {
        if(a[n-1] == b[m-1]) {
            st.push(a[n-1]);
            n--;    m--;
        } else if(dp[n-1][m] >= dp[n][m-1]) {
            n--;
        } else {
            m--;
        }
    }
    while( !st.empty() ) {
        printf("%c",st.top());
        st.pop();
    }
    return 0;
}
