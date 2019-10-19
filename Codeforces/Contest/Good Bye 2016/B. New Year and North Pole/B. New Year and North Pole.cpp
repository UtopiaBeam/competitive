#include<iostream>
using namespace std;
int n,y=0,x;
string dir;
int main(){
    cin >> n;
    while(n--){
        cin >> x >> dir;
        while(x>0){
            if(dir=="North"){
                if(y==0  || x>y){
                    cout << "NO";
                    return 0;
                }
                y-=x;
                if(y<0)     y=-y;
            }
            if(dir=="South"){
                if(y==20000 || y+x>20000){
                    cout << "NO";
                    return 0;
                }
                y+=x;
                if(y>20000) y=40000-y;
            }
            if((dir=="East" || dir=="West") && (y==0 || y==20000)){
                cout << "NO";
                return 0;
            }
            x-=40000;
        }
    }
    if(y==0)    cout << "YES";
    else        cout << "NO";
    return 0;
}
