#include <cstdio>
#include <stack>
using namespace std;
stack<int> st;
int n;
int a[1002], dp[1002], p[1002], mx = 0;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        dp[i] = 1;
    for(int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        for(int j = 1; j < i; j++) {
            if(a[j] < a[i] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
                p[i] = j;
            }
        }
        if(dp[mx] < dp[i])      mx = i;
    }
    printf("%d\n", dp[mx]);
    while(mx > 0) {
        st.push(a[mx]);
        mx = p[mx];
    }
    while( !st.empty() ) {
        printf("%d ", st.top());
        st.pop();
    }
    return 0;
}
