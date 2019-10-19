#include <cstdio>
#include <vector>
using namespace std;
int n;
vector <int> v;
int main() {
    for(int i = 1; ; i++) {
        int t = 0;
        vector <int> num;
        for(int j = 0; 1<<j <= i; j++)
            num.push_back( (i>>j)&1 );
        for(int j = num.size()-1; j >= 0; j--)
            t = 10*t + num[j];
        v.push_back(t);
        if(t > 1e9)     break;
    }
    scanf("%d", &n);
    for(int i = 0; i < v.size(); i++)
        if(n < v[i]) {
            printf("%d\n", i);
            return 0;
        }
}
