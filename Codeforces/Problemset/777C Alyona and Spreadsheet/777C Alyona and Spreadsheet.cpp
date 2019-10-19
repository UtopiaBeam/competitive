#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[100002];
int r, c, t, k, s, e;
int dp[100002], tmp[100002];
int main() {
    scanf("%d %d",&r,&c);
    for(int i = 1; i <= r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d",&t);
            a[i].push_back(t);
        }
    }
    for(int i = 1; i <= r; i++)
        dp[i] = 1<<30;
    for(int j = 0; j < c; j++) {
        tmp[1] = 1;
        for(int i = 2; i <= r; i++) {
            if(a[i][j] >= a[i-1][j])
                tmp[i] = tmp[i-1];
            else    tmp[i] = i;
        }
        for(int i = 1; i <= r; i++)
            dp[i] = min(dp[i], tmp[i]);
    }
    scanf("%d",&k);
    while(k--) {
        scanf("%d %d",&s,&e);
        if(dp[e] <= s)      printf("Yes\n");
        else        printf("No\n");
    }
    return 0;
}
