#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
char a[202];
stack<char> s;
int main(){
    scanf(" %s",a);
    for(int i=0;a[i];i++){
        if(s.empty() || a[i]=='(')
            s.push(a[i]);
        else if(s.top()=='(' && a[i]==')')
            s.pop();
        else    s.push(a[i]);
    }
    printf("%d\n",s.size());
    return 0;
}
