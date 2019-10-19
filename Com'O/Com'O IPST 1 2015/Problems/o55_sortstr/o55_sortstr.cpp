#include<iostream>
#include<algorithm>
using namespace std;
string a[100002];
int n;
int main(){
    cin >> n;
    for(int i=0;i<n;i++)    cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)    cout << a[i] << "\n";
    return 0;
}
