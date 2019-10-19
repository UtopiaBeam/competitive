#include<iostream>
using namespace std;
int n,now=1,cnt=0;
char a[10];
int main(){
    cin >> n;
    while(n--){
        cin >> a;
        if(a[0]=='A' || a[0]=='P' || a[0]=='O' || a[0]=='R')
            cnt+=now-1,now=1;
        else if(a[0]=='B' || a[0]=='M' || a[0]=='S')
            cnt+=(now<2)?   2-now:now-2,now=2;
        else    cnt+=3-now,now=3;
    }
    cout << cnt << endl;
    return 0;
}
