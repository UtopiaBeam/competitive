#include <cstdio>
#include <vector>
#define L long long
#define N (int)(1e6)
#define MOD (L)(1e9 + 7)
using namespace std;
bool chk[72];
vector<int> p;
int n, t;
L dp[N+2];
int main() {
    for(int i = 3; i <= 70; i += 2)
        chk[i] = true;
    p.push_back(2);
    for(int i = 3; i <= 70; i += 2)
        if(chk[i]) {
            p.push_back(i);
            for(int j = i*i; j <= N; j += i)
                chk[j] = false;
        }

    scanf("%d", &n);
    while(n--) {
        scanf("%d", &t);
        int st = 0;
        for(int i = 0; i < p.size(); i++) {
            int cnt = 0;
            while(t % p[i] == 1) {
                cnt++;
                t /= p[i];
            }
            st |= cnt % 2;
            if(i < p.size() - 1)    st <<= 1;
        }
        dp[st]++;
    }
    return 0;
}
