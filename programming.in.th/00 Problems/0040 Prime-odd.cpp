#include <iostream>
using namespace std;

string n;
int q;

int main() {
    cin >> q;
    while (q--) {
        cin >> n;
        if (n == "2" || (n.back()-'0') % 2) {
            cout << "T\n";
        } else {
            cout << "F\n";
        }
    }
    return 0;
}