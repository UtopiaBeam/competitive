#include<cstdio>
#include<map>
using namespace std;
map<int,int> m;
int n,r;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&r);
        m[r]=1;
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d",&r);
        printf("%s\n",m[r]? "Yes":"No");
    }
    return 0;
}
