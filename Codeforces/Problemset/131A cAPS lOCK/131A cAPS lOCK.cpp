#include<iostream>
#include<cctype>
using namespace std;
string a;
bool chk=true;
int main(){
    cin >> a;
    for(int i=1;i<a.size() && chk;i++)
        if(islower(a[i]))   chk=false;
    if(chk){
        for(int i=0;i<a.size();i++)
            if(isupper(a[i]))   a[i]=tolower(a[i]);
            else    a[i]=toupper(a[i]);
    }
    cout << a << endl;
    return 0;
}
