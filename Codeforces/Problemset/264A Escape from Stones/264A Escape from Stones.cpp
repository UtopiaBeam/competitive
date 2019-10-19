#include <cstdio>
#include <cstring>
#include <algorithm>
#define P pair<int, int>
#define F first
#define S second
#define N 1000000
using namespace std;
char s[N+2];
P ans[N+2];
int main() {
    scanf(" %s", s);
    int n = strlen(s);
    int l = 1, r = n;
    for(int i = 0; i < n; i++)
        if(s[i] == 'l')     ans[i] = P(r--, i+1);
        else        ans[i] = P(l++, i+1);
    sort(ans, ans+n);
    for(int i = 0; i < n; i++)
        printf("%d\n", ans[i].S);
    return 0;
}
