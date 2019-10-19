#include <cstdio>
#include <vector>
#define L long long
#define N (L)(1e7)
using namespace std;
vector<L> v;
bool chk[N+2];
L x;
int main() {
    v.push_back(2);
    for(int i = 3; i <= N; i += 2)
        chk[i] = true;
    for(int i = 3; i*i <= N; i += 2) {
        if( !chk[i] )       continue;
        for(int j = i*i; j <= N; j += i)
            chk[j] = false;
    }
    for(int i = 3; i <= N; i += 2)
        if(chk[i])      v.push_back(i);
    scanf("%I64d", &x);
    bool isPrime = true;
    for(L t : v) {
        if(t >= x)      break;
        if(x % t == 0) {
            isPrime = false;
            break;
        }
    }
    if(isPrime) {
        printf("1\n0\n");
        return 0;
    }
    L ans = 1;
    int cnt = 0;
    for(L t : v) {
        while(x > 0 && x % t == 0) {
            cnt++;
            x /= t;
            if(cnt <= 2)    ans *= t;
        }
    }
    if(x > 1)       cnt++;
    if(cnt > 2)     printf("1\n%I64d\n", ans);
    else            printf("2\n");
    return 0;
}
