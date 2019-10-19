#include<cstdio>
#include<set>
using namespace std;
multiset <long long> W,H;
long long w,h,n,num;
int main(){
    scanf("%I64d %I64d %I64d",&w,&h,&n);
    W.insert(0),H.insert(0),W.insert(w),H.insert(h);
    while(n--){
        char ch;
        scanf(" %c %I64d",&ch,&num);
        if(ch=='H'){
            H.insert(num);
        }
    }
}
