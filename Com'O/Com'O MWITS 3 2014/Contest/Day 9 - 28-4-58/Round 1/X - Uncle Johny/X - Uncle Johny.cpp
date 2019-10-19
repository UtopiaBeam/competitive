#include<iostream>
#include<algorithm>
using namespace std;
class song{
public:
    int in,x;
}a[100005];
int t,n,k;
bool cmp(song p,song q){
    return p.x<q.x;
}
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i].x;
            a[i].in=i+1;
        }
        cin >> k;
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++)
            if(a[i].in==k){
                cout << i+1 << endl;    break;
            }
    }
    return 0;
}
