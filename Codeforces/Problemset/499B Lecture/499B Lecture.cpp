#include<iostream>
#include<map>
using namespace std;
map <string,string> a;
int main(){
    int n,m;
    cin >> n >> m;
    while(m--){
        string first,second;
        cin >> first >> second;
        if(first.length()>second.length())    a[first]=a[second]=second;
        else    a[first]=a[second]=first;
    }
    while(n--){
        string word;
        cin >> word;
        cout << a[word] << " ";
    }
    cout << endl;
    return 0;
}
