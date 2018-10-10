#include <iostream>
#include <algorithm>
#include <map>
#define F first
#define S second
using namespace std;
map<string, int> mp, chk;
map<string, int>::iterator it;
string s, str;
int mx = 0;
int main() {
    ios::sync_with_stdio(0);
    for(int i = 0; i < 4; i++) {
        chk.clear();
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int j = 0; j < s.length(); j++)
            for(int k = 1; k+j <= s.length(); k++) {
                str = s.substr(j, k);
                if(!chk[str])       mp[str]++;
                chk[str] = 1;
            }
    }
    for(it = mp.begin(); it != mp.end(); it++) {
        if(it->S >= 3 && mx < (it->F).length() ) {
            mx = (it->F).length();
            s = it->F;
        }
    }
    cout << s << '\n';
    return 0;
}
