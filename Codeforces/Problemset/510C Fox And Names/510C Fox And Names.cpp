#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
vector<int> tp;
string s[102];
int g[30][30];
int n, inDeg[30];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++) {
            bool isDiff = false;
            for(int k = 0; k < s[i].size() && k < s[j].size(); k++) {
                int u = s[i][k]-'a', v = s[j][k]-'a';
                if(u != v) {
                    isDiff = true;
                    if(g[u][v] == 0)    inDeg[v]++;
                    g[u][v] = 1;
                    break;
                }
            }
            if( !isDiff && s[i].size() > s[j].size() ) {
                cout << "Impossible\n";
                return 0;
            }
        }
    for(int i = 0; i < 26; i++)
        if(inDeg[i] == 0)       q.push(i);
    while( !q.empty() ) {
        int u = q.front();
        q.pop();
        tp.push_back(u);
        for(int i = 0; i < 26; i++)
            if(g[u][i]) {
                inDeg[i]--;
                if(inDeg[i] == 0)
                    q.push(i);
            }
    }
    for(int i = 0; i < 26; i++)
        if(inDeg[i] != 0) {
            cout << "Impossible\n";
            return 0;
        }
    for(int i = 0; i < tp.size(); i++)
        cout << char(tp[i]+'a');
    return 0;
}
