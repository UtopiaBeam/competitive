#include <iostream>
#include <map>
#define L long long
using namespace std;
map<string, bool> mp;
L n, p, q, cnt = 0, csv = 0;
string sv, ar;
int main() {
    cin >> n >> p >> q;
    while(n--) {
        cin >> sv >> ar;
        if(!mp[sv])         csv++;
        mp[sv] = true;
        if(ar != "Eternal_City_Mac_Anu" && ar != "Warring_City_Lumina_Cloth" &&
           ar != "Celestial_City_Dol_Dona" && ar != "Dual_City_Breg_Epona")
            cnt++;
    }
    cout << p * (csv - 1) + 2 * q * cnt;
    return 0;
}
