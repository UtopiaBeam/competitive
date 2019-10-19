#include <cstdio>
#include <map>
#include <algorithm>
#define L long long
using namespace std;
map<L, bool> mp;
L b, q, l, x;
int m;
int main() {
    scanf("%I64d %I64d %I64d %d", &b, &q, &l, &m);
    while(m--) {
        scanf("%I64d", &x);
        mp[x] = true;
    }
    if(b == 0 || q == 0) {
        if(!mp[0])      printf("inf\n");
        else {
            if(b == 0)  printf("0\n");
            else        printf("1\n");
        }
        return 0;
    }
    if(q == 1) {
        if(mp[b] || abs(b) > l)
            printf("0\n");
        else            printf("inf\n");
        return 0;
    }
    if(q == -1) {
        if((mp[b] && mp[-b]) || abs(b) > l)
            printf("0\n");
        else    printf("inf\n");
        return 0;
    }
    int cnt = 0;
    while(abs(b) <= l) {
        if(!mp[b])      cnt++;
        b *= q;
    }
    printf("%d\n", cnt);
    return 0;
}
