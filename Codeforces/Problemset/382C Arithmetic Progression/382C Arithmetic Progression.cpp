#include <cstdio>
#include <map>
#include <algorithm>
#define F first
#define S second
using namespace std;
map<int, int> mp;
map<int, int>::iterator it;
int n;
int a[100002];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    if(n == 1) {
        printf("-1\n");
        return 0;
    }
    sort(a, a+n);
    if(n == 2) {
        if(a[0] == a[1])    printf("1\n%d\n", a[0]);
        else if( (a[1]-a[0]) & 1 )
            printf("2\n%d %d\n", 2*a[0] - a[1], 2*a[1] - a[0]);
        else        printf("3\n%d %d %d\n", 2*a[0] - a[1], (a[0]+a[1])/2, 2*a[1] - a[0]);
        return 0;
    }
    for(int i = 1; i < n; i++)
        mp[ a[i]-a[i-1] ]++;
    if(mp.size() > 2)       printf("0\n");
    else if(mp.size() == 1) {
        int x = a[0]-(mp.begin()->F), y = a[n-1]+(mp.begin()->F);
        if(x == y)      printf("1\n%d\n", x);
        else            printf("2\n%d %d\n", x, y);
        return 0;
    }
    else {
        int mn = 1<<30, mx = 0, mn_d, mx_d;
        for(it = mp.begin(); it != mp.end(); it++) {
            if(mn > it->S)      mn = it->S, mn_d = it->F;
            else if(mn == it->S)    mn_d = max(mn_d, it->F);
            if(mx < it->S)      mx = it->S, mx_d = it->F;
            else if(mx == it->S)    mx_d = min(mx_d, it->F);
        }
        if(mn > 1 || mn_d != 2*mx_d)        printf("0\n");
        else {
            printf("1\n");
            for(int i = 1; i < n; i++)
                if(a[i]-a[i-1] != mx_d) {
                    printf("%d\n", a[i]-mx_d);
                    break;
                }
        }
    }
    return 0;
}
