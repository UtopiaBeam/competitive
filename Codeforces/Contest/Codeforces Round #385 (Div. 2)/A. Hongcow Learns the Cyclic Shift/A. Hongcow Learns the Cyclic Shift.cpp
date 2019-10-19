#include<iostream>
#include<string>
#include<map>
using namespace std;
string s,t;
map<string,int> m;
int cnt=1;
int main(){
    cin >> s;
    m[s]=1;
    for(int i=0;i<s.size();i++){
        t=s.substr(1);
        t.append(s.begin(),s.begin()+1);
        if(!m[t])   cnt++;
        m[t]=1;
        s=t;
    }
    cout << cnt;
    return 0;
}
