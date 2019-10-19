//4 5 11
#include<cstdio>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int v,t;
P a[10];
int main(){
    scanf("%d",&v);
    for(int i=0;i<10;i++){
        scanf("%d",&t);
        a[i]=P(t,-i);
    }
    sort(a,a+10);
    for(int i=0;i<10;i++){
        t=v/a[i].F;
        int chk=0;
        for(int j=i+1;j<10;j++)
            if(t==v/a[j].F)     chk++;
    }
    return 0;
}
