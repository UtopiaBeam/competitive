#include<cstdio>
int a[500005],p=0,n,m;
int main(){
    a[2]=1;
    scanf("%d %d",&n,&m);
    for(int i=3;i<=n;i+=2)  a[i]=1;
    for(int i=3;i*i<n;i++)
        if(a[i]){
            for(int j=i*i;j<=n;j+=i)
                a[j]=0;
        }
    for(int i=2;i<=n;i++)
        if(a[i])    p++;
    if(p-m>0)   printf("%d\n",p-m);
    else    printf("0\n");
    return 0;
}
