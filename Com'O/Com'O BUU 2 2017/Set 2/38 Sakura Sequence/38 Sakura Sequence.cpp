#include <cstdio>
#include <vector>
#include <algorithm>
#define L long long
#define N 10970271
using namespace std;
vector<L> v;
int n;
L nw;
bool chk = true;
char s[12];
int main() {
    for(L i = 1; i <= 26; i++)
        v.push_back(i);
    for(int i = 0; v.size() < N; i++) {
        nw = v[i];
        for(L i = (nw+25)%26+2; i <= 26; i++)
            v.push_back( nw*26 + i );
    }
    scanf("%d", &n);
    while(n--) {
        scanf(" %s", s);
        nw = 0;     chk = true;
        for(int i = 0; s[i]; i++) {
            if(i > 0 && s[i] <= s[i-1]) {
                chk = false;
                printf("0\n");
                break;
            }
            nw *= 26;
            nw += s[i]-'a'+1;
        }
        if(chk)     printf("%d\n", lower_bound(v.begin(), v.end(), nw)-v.begin()+1);
    }
    return 0;
}
