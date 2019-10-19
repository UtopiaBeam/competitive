#include <iostream>
#include <set>
#include <algorithm>
#define N 10000
using namespace std;
string s;
bool dp[N+5][2];
set<string> st;
int main() {
    cin >> s;
    int n = s.size();
    s = "#" + s + "###";
    if(n >= 7)      dp[n-1][0] = true;
    if(n >= 8)      dp[n-2][1] = true;
    for(int i = n-1; i > 5; i--) {
        if(dp[i+2][1] || dp[i+2][0] && s.substr(i, 2) != s.substr(i+2, 2) )
            dp[i][0] = true;
        if(dp[i+3][0] || dp[i+3][1] && s.substr(i, 3) != s.substr(i+3, 3) )
            dp[i][1] = true;
    }
    for(int i = 1; i <= n; i++) {
        if(dp[i][0])        st.insert( s.substr(i, 2) );
        if(dp[i][1])        st.insert( s.substr(i, 3) );
    }
    cout << st.size() << "\n";
    for(string x : st)
        cout << x << "\n";
    return 0;
}
