#include<iostream>
#include<map>
using namespace std;
map<string,int> m;
int n,q,l;
string a;
int main(){
    cin >> n >> q >> l;
    while(n--){
        cin >> a;
        m[a]=1;
    }
    while(q--){
        cin >> a;
        if(m[a])    cout << "Accepted\n";
        else        cout << "Rejected\n";
    }
    return 0;
}
