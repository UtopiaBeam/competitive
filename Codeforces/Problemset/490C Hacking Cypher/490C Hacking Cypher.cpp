#include <cstdio>
#include <cstring>
#include <deque>
#define L long long
#define N 1000000
using namespace std;
char s[N+2];
deque<char> x, y;
L a, b, tx, ty;
L pow[N+2] = {1};
int main() {
    scanf(" %s %I64d %I64d", s, &a, &b);
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        y.push_back(s[i]);
        ty = (10*ty + s[i]-'0') % b;
        pow[i+1] = (pow[i] * 10) % b;
    }
    for(int i = 0; i < len-1; i++) {
        x.push_back(s[i]);
        y.pop_front();
        tx = ( (10*tx) + (s[i]-'0') ) % a;
        ty = (ty - ( (s[i]-'0') * pow[len-1-i] ) % b + b) % b;
        if(s[i+1] == '0')       continue;
        if(tx == 0 && ty == 0) {
            printf("YES\n");
            for(int j = 0; j < x.size(); j++)
                printf("%c", x[j]);
            printf("\n");
            for(int j = 0; j < y.size(); j++)
                printf("%c", y[j]);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
