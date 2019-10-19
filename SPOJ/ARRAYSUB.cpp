#include <cstdio>
#include <deque>
using namespace std;
deque<int> mx;
int n, k, a[100002];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    scanf("%d", &k);
    for(int i = 0; i < k-1; i++) {
        while(!mx.empty() && a[mx.back()] < a[i])
            mx.pop_back();
        mx.push_back(i);
    }
    for(int i = k-1; i < n; i++) {
        while(!mx.empty() && mx.front() <= i-k)
            mx.pop_front();
        while(!mx.empty() && a[mx.back()] < a[i])
            mx.pop_back();
        mx.push_back(i);
        printf("%d ", a[mx.front()]);
    }
    return 0;
}
