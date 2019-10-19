#include<cstdio>
#include<vector>
using namespace std;
vector <int> a;
int n,pow=1,t;
int main(){
    scanf("%d",&n);
    while(1<<pow<n+2)    pow++;
    pow--;
    t=n-(1<<pow)+1;
    while(pow--){
        a.push_back(t%2);
        t/=2;
    }
    for(int i=a.size()-1;i>=0;i--)
        if(a[i])    printf("7");
        else    printf("4");
    return 0;
}
