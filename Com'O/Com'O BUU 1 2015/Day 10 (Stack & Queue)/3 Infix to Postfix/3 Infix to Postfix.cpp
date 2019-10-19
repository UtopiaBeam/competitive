#include<cstdio>
#include<cctype>
#include<cstring>
#include<stack>
using namespace std;
stack<char> s;
int q;
char a[102];
int f(char ch){
    if(ch=='+' || ch=='-')  return 1;
    if(ch=='*' || ch=='/')  return 2;
    if(ch=='^')     return 3;
    return 0;
}
int main(){
    scanf("%d ",&q);
    while(q--){
        gets(a);
        int len=strlen(a);
        for(int i=0;i<len;i++){
            if(a[i]==')'){
                while(!s.empty() && s.top()!='('){
                    printf("%c ",s.top());  s.pop();
                }
                s.pop();
            }
            else if(a[i]=='(')   s.push(a[i]);
            else if(isalpha(a[i]))  printf("%c ",a[i]);
            else if(isdigit(a[i])){
                int t=0;
                while(i<len && isdigit(a[i]))    t*=10,t+=a[i++]-'0';
                printf("%d ",t);    i--;
            }
            else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/' || a[i]=='^'){
                while(!s.empty() && f(s.top())>=f(a[i])){
                    printf("%c ",s.top());  s.pop();
                }
                s.push(a[i]);
            }
        }
        while(!s.empty()){
            printf("%c ",s.top());  s.pop();
        }
        printf("\n");
    }
    return 0;
}
