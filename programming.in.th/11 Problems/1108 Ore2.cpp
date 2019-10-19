#include <cstdio>
#include <deque>
#include <algorithm>
#define L long long
#define N (int)1e6
using namespace std;
deque<int> mx;
int n;
L k, a[N+2], dp[N+2];
int main() {
    scanf("%d %lld", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", a+i);
        a[i] += a[i-1];
    }
    a[n+1] = a[n];
    int l = 0;
    for(int i = 1; i <= n+1; i++) {
        while(a[i-1] - a[l] > k) {
            l++;
        }
        while(!mx.empty() && dp[mx.back()] + a[i-1] - a[mx.back()] < dp[i-1])
            mx.pop_back();
        mx.push_back(i-1);
        while(!mx.empty() && mx.front() < l)
            mx.pop_front();
        dp[i] = dp[mx.front()] + a[i-1] - a[mx.front()];
    }
    printf("%lld\n", dp[n+1]);
    return 0;
}
