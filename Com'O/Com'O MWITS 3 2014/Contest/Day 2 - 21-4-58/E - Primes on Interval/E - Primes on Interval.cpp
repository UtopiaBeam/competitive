#include<cstdio>
int st[2000005],p[1000005]={0,0,1},a,b,k;
int main(){
    for(int i=3;i<1000000;i+=2)     p[i]=1;
    for(int i=3;i*i<1000000;i+=2)
        if(p[i])
            for(int j=i*i;j<1000000;j+=i)   p[j]=0;
    scanf("%d %d %d",&a,&b,&k);
    for(int i=2*(b-a)-1,j=0;i>=(b-a);i--,j--)
        if(p[b-j])  st[i]=1;
    return 0;
}
