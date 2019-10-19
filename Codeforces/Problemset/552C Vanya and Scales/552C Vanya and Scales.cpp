#include<cstdio>
#include<vector>
using namespace std;
vector<int> a;
int w,m;
int main(){
    scanf("%d %d",&w,&m);
    if(w==2 || w==3){
        printf("YES\n");       return 0;
    }
    while(m){
        a.push_back(m%w);
        m/=w;
    }
    for(int i=0;i<a.size();i++){
        if(a[i]==w-1){
            a[i]=0;
            if(i<a.size()-1)    a[i+1]++;
            else    a.push_back(1);
        }
        else if(a[i]>=w){
            a[i]%=w;
            if(i<a.size()-1)    a[i+1]++;
            else    a.push_back(1);
        }
        if(a[i]!=0 && a[i]!=1){
            printf("NO\n");     return 0;
        }
    }
    printf("YES\n");
    return 0;
}
