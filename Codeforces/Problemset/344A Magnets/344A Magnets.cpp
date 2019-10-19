#include<iostream>
using namespace std;
int main(){
    string last;
    int n,cnt=1;
    cin >> n;
    cin >> last;
    while(--n){
        string a;
        cin >> a;
        if(last.compare(a))     cnt++,last=a;
    }
    cout << cnt << endl;
    return 0;
}
