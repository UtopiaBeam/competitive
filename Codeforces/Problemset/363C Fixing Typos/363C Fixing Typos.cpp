#include <iostream>
using namespace std;
string s, ans;
int main() {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(ans.size() > 1 && ans.back() == s[i] && ans[ans.size()-2] == s[i])
            continue;
        else if(ans.size() > 2 && ans.back() == s[i] && ans[ans.size()-2] == ans[ans.size()-3])
            continue;
        else        ans += s[i];
    }
    cout << ans;
    return 0;
}
