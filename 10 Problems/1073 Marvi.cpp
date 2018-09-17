#include<cstdio>
#include<algorithm>
int n,l,t,ans[70005];
int main(){
    scanf("%d %d %d",&l,&t,&n);
    for(int i=0;i<n;i++){
        char pos;
        int x;
        scanf("%d %c",&x,&pos);
        if(pos=='L'){
            if(x-t>=0)   ans[i]=x-t;
            else{
                ans[i]=(t-x)%(2*l);
                if(ans[i]>l)    ans[i]=2*l-ans[i];
            }
        }
        else{
            if(x+t<=l)     ans[i]=x+t;
            else{
                ans[i]=(t-l+x)%(2*l);
                if(ans[i]<=l)    ans[i]=l-ans[i];
                else    ans[i]-=l;
            }
        }
    }
    std::sort(ans,ans+n);
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
