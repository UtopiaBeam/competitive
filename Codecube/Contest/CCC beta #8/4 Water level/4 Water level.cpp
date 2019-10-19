#include<cstdio>
#include<stack>
using namespace std;
int n,a[1000002],h[1000002];
stack<int> s;
void f(){
    stack<int> t;
    while(!s.empty()){
        printf("%d\n",s.top());
        t.push(s.top());
        s.pop();
    }
    while(!t.empty()){
        s.push(t.top());
        t.pop();
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++){
        while(!s.empty() && a[s.top()]<=a[i])
            s.pop();
        s.push(i);
    }
    for(int i=n-1;i>0;i--){
        if(i==s.top()-1){
            if(s.size()==1){
                s.pop();
                break;
            }
            h[i]=a[s.top()];
            s.pop();
        }
        else    h[i]=h[i+1];
    }
    for(int i=n;i>0;i--){
        while(!s.empty() && a[s.top()]<=a[i])
            s.pop();
        s.push(i);
    }
    for(int i=1;i<n;i++){
        if(i==s.top()){
            if(s.size()==1){
                s.pop();
                break;
            }
            h[i]=a[s.top()];
            s.pop();
        }
        else    h[i]=h[i-1];
    }
//    printf("\n");
    for(int i=1;i<n;i++)
        printf("%d ",h[i]);
    return 0;
}
