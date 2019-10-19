#include<cstdio>
int n,m,y,cnt;
int pow(int a,int b){
    if(b==0)    return 1;
    int x=pow(a,b/2);
    if(b%2)     return (a*x*x)%m;
    return (x*x)%m;
}
int main(){
    int chk=1;
    scanf("%d %d %d",&n,&m,&y);
    for(int i=0;i<m;i++)
        if(pow(i,n)==y)     printf("%d ",i),chk=0;
    if(chk)     printf("-1\n");
    return 0;
}
