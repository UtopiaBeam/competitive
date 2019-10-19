#include<cstdio>
#include<cstring>
#include<cctype>
#include<stack>
#include<vector>
using namespace std;
char a[500];
stack <char> stk;
stack <double> cal;
vector <char> b;
int main(){
    scanf(" %s",a);
    int len=strlen(a);
    //Infix -> Postfix
    for(int i=0;i<len;i++)
        if(isdigit(a[i]))   b.push_back(a[i]);
        else if(a[i]=='('){
            stk.push(a[i]);
            while(a[++i]!=')')
                if(isdigit(a[i]))  b.push_back(a[i]);
                else    stk.push(a[i]);
            while(stk.top()!='(')
                b.push_back(stk.top()),stk.pop();
            stk.pop();
        }
        else if(stk.empty())    stk.push(a[i]);
        else if((a[i]=='*'||a[i]=='/') && (stk.top()=='+'&&stk.top()=='-'))   stk.push(a[i]);
        else{
            while(!stk.empty()){
                if((a[i]=='+'||a[i]=='-')||((a[i]=='*'||a[i]=='/') && (stk.top()=='*'||stk.top()=='/')))
                    b.push_back(stk.top()),stk.pop();
                else if((a[i]=='*'||a[i]=='/') && (stk.top()=='+'||stk.top()=='-'))     break;
            }
            stk.push(a[i]);
        }
    while(!stk.empty())     b.push_back(stk.top()),stk.pop();
    for(int i=0;i<(int)b.size();i++)
        printf("%c",b[i]);
    printf("\n");
    //Calculation
    for(int i=0;i<(int)b.size();i++){
        if(isdigit(b[i]))   cal.push(b[i]-'0');
        else{
            double t2=cal.top();    cal.pop();
            double t1=cal.top();    cal.pop();
            if(b[i]=='+')   cal.push(t1+t2);
            if(b[i]=='-')   cal.push(t1-t2);
            if(b[i]=='*')   cal.push(t1*t2);
            if(b[i]=='/')   cal.push(t1/t2);
        }
    }
    printf("%lf\n",cal.top());
    return 0;
}
