#include<cstdio>
#include<vector>
using namespace std;
vector<int> pr;
int p[5000005]={0,0,1},t,a,b;
int main(){
    for(int i=3;i<=5000000;i+=2)    p[i]=1;
    for(int i=3;i*i<=5000000;i+=2)
        if(p[i])
            for(int j=i*i;j<=5000000;j+=i)
                p[j]=0;
    pr.push_back(2);
    for(int i=3;i<=5000000;i+=2)
        if(p[i])    pr.push_back(i);
    for(int i=3;i<=5000000;i++){
        t=i;
        for(int j=0;t>=pr[j]*pr[j];j++){
            int cnt=0;
            while(t%pr[j]==0)
                t/=pr[j],cnt++;
            if(t==1 || p[t]){
                p[i]=p[t]+cnt;  break;
            }
        }
    }
    for(int i=3;i<=5000000;i++) p[i]+=p[i-1];
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        printf("%d\n",p[a]-p[b]);
    }
    return 0;
}
