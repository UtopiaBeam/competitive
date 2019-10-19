#include<iostream>
#include<cctype>
#include<stack>
using namespace std;
int n;
string a;
stack<char> s;
int main(){
    cin >> n;
    while(n--){
        cin >> a;
        for(int i=0;i<a.size();i++)
            if(isalpha(a[i]))   cout << a[i];
            else if(a[i]==')'){
                while(s.top()!='('){
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            }
            else    s.push(a[i]);
        cout << endl;
    }
    return 0;
}
