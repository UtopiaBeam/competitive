#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int m;
int s, e;
int g[7][7];
int chk[7];
vector<int> path;
vector< vector<int> > ans;
bool cmp(vector<int> x, vector<int> y) {
    if(x.size() != y.size())    return x.size() < y.size();
    for(int i = 0; i < x.size(); i++) {
        if(x[i] < y[i])     return true;
        if(x[i] > y[i])     return false;
    }
}
void dfs(int u) {
    if(chk[u] == 1)     return;
    path.push_back(u);
    chk[u]++;
    if(u == 2 && chk[u] == 1) {
        ans.push_back(path);
        path.pop_back();
        chk[u]--;
        return;
    }
    for(int i = 1; i <= 5; i++) {
        if(g[u][i] && chk[i] == 0)
            dfs(i);
    }
    path.pop_back();
    chk[u]--;
}
int main() {
    scanf("%d", &m);
    while(m--) {
        scanf("%d %d", &s, &e);
        g[s][e] = g[e][s] = 1;
    }
    chk[2] = -1;
    dfs(2);
    sort(ans.begin(), ans.end(), cmp);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++)
            printf("%d",ans[i][j]);
        printf("\n");
    }
    return 0;
}
