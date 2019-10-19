#include<stdio.h>
double a[200010];
int main(){
    char ch;
    int n,m,i,j,k,cnt,now;
    scanf("%d %d",&n,&m);
    for(i=0,j=0;i<m+n;i++){
        cnt=1;
        scanf(" %c",&ch);
        if(ch=='A'){
            scanf("%lf",&a[j]);
            now=j;  j++;
        }
        if(ch=='B'){
            for(k=j-1;k>=0;k--)
                if(a[k]>a[now]){
                    cnt++;  now=k;
                }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
