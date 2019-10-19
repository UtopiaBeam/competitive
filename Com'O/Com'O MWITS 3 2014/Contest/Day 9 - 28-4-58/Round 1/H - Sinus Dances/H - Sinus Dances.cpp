#include<iostream>
using namespace std;
int n;
void printA(int now,int b){
    if(now==0)      return ;
    if(now!=b){
        if((b-now)%2)   cout << "-";
        else    cout << "+";
    }
    cout << "sin(" << b-now+1;
    printA(now-1,b);
    cout << ")";
}
void printS(int now){
    if(now==0)      return ;
    if(now!=n)      cout << "(";
    printS(now-1);
    printA(now,now);
    cout << "+" << n-now+1;
    if(now!=n)      cout << ")";
}
int main(){
    cin >> n;
    printS(n);
}
