#include<iostream>
using namespace std;
int n,a[105]={0},x,y;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=2;i<=n;i++)
        a[i]+=a[i-1];
    cin >> x >> y;
    if(x>y)     swap(x,y);
    if(a[y-1]-a[x-1]<=a[x-1]+a[n]-a[y-1])
        cout << a[y-1]-a[x-1] << endl;
    else    cout << a[x-1]+a[n]-a[y-1] << endl;
    return 0;
}
