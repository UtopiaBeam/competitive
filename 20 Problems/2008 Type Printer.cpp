#include<iostream>
#include<algorithm>
using namespace std;
int n;
string a[25002],t;
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    return 0;
}
