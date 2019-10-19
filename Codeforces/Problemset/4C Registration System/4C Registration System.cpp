#include<bits/stdc++.h>
using namespace std;
map <string,int> cnt;
string str;
int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> str;
        if(cnt[str])
            cout << str << cnt[str] << endl;
        else    cout << "OK" << endl;
        cnt[str]++;
    }
    return 0;
}
