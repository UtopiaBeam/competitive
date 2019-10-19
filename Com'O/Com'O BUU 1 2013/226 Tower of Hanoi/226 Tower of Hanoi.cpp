#include<cstdio>
#include<cstring>
int q,n,p,a[5][12],b[5],cnt;
void f(int s,int e,int m,int num){
    if(num==0)  return ;
    f(s,m,e,num-1);
    if(cnt++>=p)    return ;
    a[e][++b[e]]=a[s][b[s]--];
    f(m,e,s,num-1);
}
int main(){
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        cnt=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d %d",&n,&p);
        for(int j=1;j<=n;j++)   a[0][j]=n-j+1;
        b[0]=n;
        f(0,2,1,n);
        printf("Case %d:\n",i);
        for(int j=0;j<3;j++){
            printf("%c: ",'A'+j);
            if(b[j]){
                for(int k=1;k<=b[j];k++)
                    printf("%d ",a[j][k]);
            }
            else    printf("X");
            printf("\n");
        }
    }
    return 0;
}
