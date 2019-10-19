#include<iostream>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        int n,t=5,cnt=0;
        cin >> n;
        while(n/t)  cnt+=n/t,t*=5;
        cout << cnt << endl;
    }
    return 0;
}
