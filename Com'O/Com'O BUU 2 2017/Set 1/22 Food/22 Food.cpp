#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, t;
int x[10], a[10];
int main() {
    scanf("%d %d", &n, &m);
    while(m--) {
        scanf("%d", &t);
        x[t] = 1;
    }
    for(int i = 0; i < n; i++)
        a[i] = i+1;
    do {
        if(x[a[0]])     continue;
        for(int i = 0; i < n; i++)
            printf("%d ",a[i]);
        printf("\n");
    } while(next_permutation(a, a+n));
    return 0;
}
