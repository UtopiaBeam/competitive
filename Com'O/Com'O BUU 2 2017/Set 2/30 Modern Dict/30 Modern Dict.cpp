#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> tp;
int n, u, cnt, nd = 0;
int g[30][30], inDeg[30], chk[30];
char s[102][12], dfsChk[30];
bool isMul = false, isCyc = false;
void dfs(int u) {
    if(dfsChk[u])       return;
    nd--;   dfsChk[u] = true;
    for(int i = 0; i < 26; i++)
        if(chk[i] && g[u][i])
            dfs(i);
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf(" %s", s[i]);
        for(int j = 0; s[i][j]; j++) {
            nd += chk[ s[i][j]-'a' ];
            chk[ s[i][j]-'a' ] = 1;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            for(int k = 0; s[i][k] && s[j][k]; k++) {
                if(s[i][k] != s[j][k]) {
                    if(g[ s[i][k]-'a' ][ s[j][k]-'a' ])     break;
                    chk[ s[i][k]-'a' ] = chk[ s[j][k]-'a' ] = 2;
                    g[ s[i][k]-'a' ][ s[j][k]-'a' ] = 1;
                    inDeg[ s[j][k]-'a' ]++;
                    break;
                }
            }
    //Check connectivity
    for(int i = 0; i < 26; i++) {
        if(chk[i] == 1 && inDeg[i] == 0) {
            dfs(i);
            if(nd !=0)      isMul = true;
            break;
        }
    }
    //Topo sort
    for(int i = 0; i < 26; i++)
        if(chk[i] == 2 && inDeg[i] == 0) {
            q.push(i);      cnt++;
        }
    if(cnt > 1)     isMul = true;
    while( !q.empty() ) {
        u = q.front();
        q.pop();
        tp.push_back(u);
        cnt = 0;
        for(int i = 0; i < 26; i++)
            if(g[u][i]) {
                inDeg[i]--;
                g[u][i] = 0;
                if(inDeg[i] == 0) {
                    q.push(i);      cnt++;
                }
            }
        if(cnt > 1)     isMul = true;
    }
    for(int i = 0; i < 26; i++)
        if(inDeg[i] != 0)   isCyc = true;
    if(isCyc)           printf("!\n");
    else if(isMul)      printf("?\n");
    else for(int i = 0; i < tp.size(); i++)
        printf("%c", tp[i]+'a');
    return 0;
}
