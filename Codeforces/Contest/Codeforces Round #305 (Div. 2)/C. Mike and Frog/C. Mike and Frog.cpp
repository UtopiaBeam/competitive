#include<cstdio>
long long m,h1,h2,x1,x2,y1,y2,a1,a2,cnt=0;
int main(){
    scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d",&m,&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
    while(h1!=a1 || h2!=a2){
        if(cnt>m){
            printf("-1\n");     return 0;
        }
        h1*=x1,h1+=y1,h1%=m;
        h2*=x2,h2+=y2,h2%=m;
        cnt++;
    }
    printf("%I64d\n",cnt);
    return 0;
}
