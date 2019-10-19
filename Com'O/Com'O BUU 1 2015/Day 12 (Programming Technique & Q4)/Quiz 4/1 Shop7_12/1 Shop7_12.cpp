#include<cstdio>
int a,b,n,t;
int main(){
    scanf("%d %d %d",&a,&b,&n);
    while(n--){
        int mn=1e9,ans=0;
        scanf("%d",&t);
        for(int i=0;i<=t/a+(t%a!=0);i++){
            int aa=a*i,bb=0;
            if(t>=aa)   bb=(t-aa)/b*b+((t-aa)%b!=0)*b;
            if(mn>aa+bb-t)  mn=aa+bb-t,ans=aa+bb;
        }
        printf("%d\n",ans);
    }
    return 0;
}
