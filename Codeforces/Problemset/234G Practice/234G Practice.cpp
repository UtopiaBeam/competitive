#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int n;
vector<int> v;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int t = (int)log2(n-1)+1;
    printf("%d\n", t);
    for(int i = 0; i < t; i++) {
        int cnt = 0;
        v.clear();
        for(int j = 1; j <= n; j++) {
            if( (j>>i)&1 )
                v.push_back(j);
        }
        printf("%d ", v.size());
        for(int j = 0; j < v.size(); j++)
            printf("%d ", v[j]);
        printf("\n");
    }
    return 0;
}
