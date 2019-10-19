#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
stack <char> a;
char s[200],len;
int main(){
    scanf(" %s",s);
    len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='(' || a.empty())   a.push(s[i]);
        if(s[i]==')' && a.top()=='(')   a.pop();
    }
    if(a.empty())   printf("Balance\n");
    else    printf("Unbalance\n");
    return 0;
}
