#include<iostream>
using namespace std;
int n,m,a,now=1;
long long cnt=0;
int main(){
    cin >> n >> m;
    while(m--){
        cin >> a;
        cnt+=(a-now+n)%n;
        now=a;
    }
    cout << cnt << endl;
    return 0;
}
