#include<cstdio>
#include<algorithm>
using namespace std;
int n,sum=0,mn=1<<30;
void f(int x){
    if((sum>>x)%2)  sum-=1<<x;
    else    sum+=1<<x;
}
int main(){
    scanf("%d",&n);
    for(int i=0,tmp,t=1;i<n;i++,t*=2){
        scanf("%d",&tmp);
        sum+=tmp*t;
    }
    for(int i=0;i<(1<<n);i++){
        int cnt=0;
        for(int j=0;j<n;j++)
            if((i>>j)%2){
                f(j),cnt++;
                if(j>0)     f(j-1);
                if(j<n-1)   f(j+1);
            }
        if(!sum)    mn=min(cnt,mn);
        for(int j=0;j<n;j++)
            if((i>>j)%2){
                f(j);
                if(j>0)     f(j-1);
                if(j<n-1)   f(j+1);
            }
    }
    if(mn==1<<30)   printf("-1\n");
    else    printf("%d\n",mn);
    return 0;
}
