#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class C{
public:
    string s[5];
    void f(){   sort(s,s+3);  }
}t;
vector<C> v;
int n,mx=(int)-1e9,cnt=0;
bool cmp(C a,C b){
    for(int i=0;i<3;i++)
        if(a.s[i].compare(b.s[i]))  return a.s[i].compare(b.s[i])<0;
    return false;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++)
            cin >> t.s[j];
        t.f();
        v.push_back(t);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(v[i].s[j].compare(v[i-1].s[j])!=0){
                cnt=0;      break;
            }
            if(j==2){
                if(!cnt)    cnt++;
                cnt++;
            }
        }
        mx=max(mx,cnt);
    }
    cout << mx << "\n";
    return 0;
}
