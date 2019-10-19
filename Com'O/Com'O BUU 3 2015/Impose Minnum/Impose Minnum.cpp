#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
string s[100002];
bool cmp(string a,string b){
    string c=a+b,d=b+a;
    return c.compare(d)<0;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> s[i];
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++)
        cout << s[i];
    return 0;
}
