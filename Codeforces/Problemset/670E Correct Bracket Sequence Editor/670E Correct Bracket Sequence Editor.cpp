#include<cstdio>
#include<stack>
using namespace std;
stack<int> s;
int n,m,nw,l[500002],r[500002],p[500002];
char a[500002],b[500002];
int main(){
    scanf("%d %d %d",&n,&m,&nw);
    scanf(" %s %s",a,b);
    for(int i=0;i<=n+1;i++)
        l[i]=i-1,r[i]=i+1;
    for(int i=0;a[i];i++)
        if(a[i]=='(')   s.push(i);
        else{
            p[s.top()+1]=i+1;
            p[i+1]=s.top()+1;
            s.pop();
        }
    for(int i=0;b[i];i++){
        if(b[i]=='L')   nw=l[nw];
        if(b[i]=='R')   nw=r[nw];
        if(b[i]=='D'){
            int x=nw,y=p[nw];
            if(x>y)     swap(x,y);
            r[l[x]]=r[y];
            l[r[y]]=l[x];
            nw=r[y];
            if(nw>n)    nw=l[nw];
        }
    }
    for(int i=r[0];i<=n;i=r[i])
        printf("%c",a[i-1]);
    return 0;
}
