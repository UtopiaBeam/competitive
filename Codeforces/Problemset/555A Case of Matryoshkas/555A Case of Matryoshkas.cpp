#include<cstdio>
int n,k,m,a[100005],cnt=0;
int main(){
    scanf("%d %d",&n,&k);
    while(k--){
        scanf("%d",&m);
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        if(a[0]==1){
            for(int i=1;i<m;i++)
                if(a[i]!=i+1)   break;
                else    cnt-=2;
        }
        cnt+=m-1;
    }
    printf("%d\n",cnt+n-1);
    return 0;
}
