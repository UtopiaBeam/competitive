#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> x, y;
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= min(n, m); i++) {
        x.push_back(i);
        y.push_back(min(n, m) - i);
    }
    printf("%d\n", x.size());
    for(int i = 0; i < x.size(); i++)
        printf("%d %d\n", x[i], y[i]);
    return 0;
}
