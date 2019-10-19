#include<iostream>
#include<algorithm>
using namespace std;
int a[20];
int main(){
    int i;
    for(i=0;i<20;i++)
        cin>>a[i];
    sort(a,a+20);
    for(i=0;i<20;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}
