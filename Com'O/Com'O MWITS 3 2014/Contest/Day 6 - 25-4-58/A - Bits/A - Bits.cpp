#include<cstdio>
#include<vector>
using namespace std;
vector <int> L,R;
int n;
void con(int num,int chk){
    if(num==0)     return ;
    if(chk)     R.push_back(num%2);
    else        L.push_back(num%2);
    con(num/2,chk);
}
int main(){
    long long l,r;
    scanf("%d",&n);
    while(n--){
        L.clear(),R.clear();
        scanf("%I64d %I64d",&l,&r);
        con(l,0);     con(r,1);
        for(int i=L.size()-1;i>=0;i--)
            printf("%d",L[i]);
        printf(" ");
        for(int i=R.size()-1;i>=0;i--)
            printf("%d",R[i]);
        printf("\n");
    }
}
