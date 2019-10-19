#include<cstdio>
int p,cnt=0;
int main(){
    scanf("%d",&p);
    for(int i=1;i*i<=p;i++)
        if(i*i==p)  cnt++;
        else if(p%i==0) cnt+=2;
    printf("%d\n",cnt);
    return 0;
}
