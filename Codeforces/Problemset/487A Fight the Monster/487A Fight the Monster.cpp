#include <cstdio>
#include <algorithm>
using namespace std;
int hp[2], atk[2], def[2];
int h, a, b;
int main() {
    for(int i = 0; i < 2; i++)
        scanf("%d %d %d", hp+i, atk+i, def+i);
    scanf("%d %d %d", &h, &a, &b);
    int mn = 1<<30;
    for(int i = max(atk[0], def[1]+1); i <= max(atk[0], hp[1]+def[1]); i++)
        for(int j = def[0]; j <= max(def[0], atk[1]); j++) {
            int dmg = 0;
            int m_hp = hp[1];
            while(m_hp > 0) {
                dmg += max(0, atk[1] - j);
                m_hp -= max(0, i - def[1]);
            }
            mn = min(mn, max(0, h*(dmg-hp[0]+1)) + a*(i-atk[0]) + b*(j-def[0]));
        }
    printf("%d\n", mn);
    return 0;
}
