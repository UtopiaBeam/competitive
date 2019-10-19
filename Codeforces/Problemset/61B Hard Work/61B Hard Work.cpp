#include<iostream>
#include<algorithm>
#include<vector>
#include<cctype>
using namespace std;
vector<string> a;
int n;
string b;
void f(){
    for(int i=0;i<b.size();i++)
        if(!isalpha(b[i]))     b.erase(b.begin()+i),i--;
        else    b[i]=tolower(b[i]);
}
int main(){
    for(int i=0;i<3;i++){
        cin >> b;
        f();
        a.push_back(b);
    }
    cin >> n;
    while(n--){
        bool chk=true;
        sort(a.begin(),a.end());
        cin >> b;
        f();
        do{
            if(!b.compare(0,a[0].size(),a[0]) && !b.compare(a[0].size(),a[1].size(),a[1]) && !b.compare(a[0].size()+a[1].size(),a[2].size(),a[2])){
                chk=false,cout << "ACC\n";
            }
        }while(next_permutation(a.begin(),a.end()));
        if(chk)     cout << "WA\n";
    }
    return 0;
}
