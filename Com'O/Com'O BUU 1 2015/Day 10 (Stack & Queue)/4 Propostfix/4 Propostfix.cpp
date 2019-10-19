#include<cstdio>
#include<cstring>
#include<cctype>
#include<stack>
#define ll long long
using namespace std;
ll t;
int q,len;
char a[102];
int main(){
    scanf("%d ",&q);
    while(q--){
        int chk=1;
        stack<ll> s;
        gets(a);
        len=strlen(a);
        if(a[len-1]=='\r')  len--;
        for(int i=0;i<len;i++){
            if(a[i]==' ')   continue;
            if(a[i]=='-' && isdigit(a[i+1])){
                t=0,i++;
                while(isdigit(a[i]))  t*=10,t+=a[i++]-'0';
                s.push(-t);     continue;
            }
            if(isdigit(a[i])){
                t=0;
                while(isdigit(a[i]))    t*=10,t+=a[i++]-'0';
                s.push(t);      continue;
            }
            if(s.size()<2){
                chk=0;  break;
            }
            ll c=s.top();  s.pop();
            ll b=s.top();  s.pop();
            if(a[i]=='+')  s.push(b+c);
            else if(a[i]=='-')  s.push(b-c);
            else if(a[i]=='*')  s.push(b*c);
        }
        if(chk && s.size()==1)  printf("%lld\n",s.top());
        else    printf("No Solution\n");
    }
    return 0;
}
