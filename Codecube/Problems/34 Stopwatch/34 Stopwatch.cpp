#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int q,t,n,m,s,ms;
int main(){
    scanf("%d",&q);
    while(q--){
        int in=0,b=0,a[10]={},d[10]={};
        vector<int> num;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&t);
            a[t]=-1;
        }
        for(int i=0;i<10;i++)
            if(!a[i])   a[i]=in++,b++;
        scanf("%d:%d:%d",&m,&s,&ms);
        ms+=s*100+m*6000;   //?
        int dig=log10(ms);
//        printf("%d, %d\n",ms,dig);
        for(int i=0;i<=dig;i++)     num.push_back(a[ms%10]),ms/=10;
        for(int i=dig;i>=0;i--)     ms*=b,ms+=num[i];//,printf("%d",num[i]);
//        printf("\n");
        m=ms/6000,ms%=6000;
        s=ms/100,ms%=100;
        printf("%02d:%02d:%02d\n",m,s,ms);
    }
    return 0;
}
