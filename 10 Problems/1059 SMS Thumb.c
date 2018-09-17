#include<stdio.h>
char a[5][5][5]={"","CAB","FDE","","","IGH","LJK","OMN","","","SPQR","VTU","ZWXY"},ans[100];
int main(){
    int n,m,x,y,i,nowx=0,nowy=0,in=0;
    scanf("%d %d %d",&n,&i,&m);
    if(i!=1){
        if(i!=7 && i!=9)    ans[in++]=a[nowx=(--i)/3][nowy=i%3][m%3];
        else    ans[in++]=a[nowx=(--i)/3][nowy=i%3][m%4];
    }
    while(--n){
        scanf("%d %d %d",&x,&y,&m);
        nowx+=y,nowy+=x;
        if(nowx==0 && nowy==0){
            in-=m;
            if(in<0)    in=0;
        }
        else if(nowx==2 && (nowy==0||nowy==2))
            ans[in++]=a[nowx][nowy][m%4];
        else
            ans[in++]=a[nowx][nowy][m%3];
    }
    if(in==0)   printf("null\n");
    else{
        for(i=0;i<in;i++)
            printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}
