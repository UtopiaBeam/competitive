#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
multiset<int> s;
int n,x;
char ch;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf(" %c %d",&ch,&x);
        if(ch=='+')     s.insert(x);
        if(ch=='-')     s.erase(s.find(x));
        if(ch=='?'){
            int mx=0;
            for(multiset<int>::iterator it=s.begin();it!=s.end();it++)
                mx=max(mx,x^(*it));
            printf("%d\n",mx);
        }
    }
    return 0;
}
