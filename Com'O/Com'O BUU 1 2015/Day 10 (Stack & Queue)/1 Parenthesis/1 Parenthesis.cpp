#include<cstdio>
#include<stack>
using namespace std;
int q;
char a[130];
int main(){
    scanf("%d",&q);
    while(q--){
        int chk=1;
        stack<char> s;
        scanf(" %s",a);
        for(int i=0;a[i];i++){
            if(a[i]=='(' || a[i]=='[')  s.push(a[i]);
            else if(s.empty())  chk=0;
            else if(a[i]==')' && s.top()=='(' || a[i]==']' && s.top()=='[') s.pop();
            else    chk=0;
        }
        if(chk && s.empty())    printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
