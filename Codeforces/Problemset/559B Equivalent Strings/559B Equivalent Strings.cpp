#include<iostream>
using namespace std;
string a,b;
string f(string s){
    if(s.size()%2)  return s;
    string s1=f(s.substr(0,s.size()/2)),s2=f(s.substr(s.size()/2));
    return s1<s2?   s1+s2:s2+s1;
}
int main(){
    cin >> a >> b;
    if(f(a)==f(b))  cout << "YES\n";
    else    cout << "NO\n";
    return 0;
}
