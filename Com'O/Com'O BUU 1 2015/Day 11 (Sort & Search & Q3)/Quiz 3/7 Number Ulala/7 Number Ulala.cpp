#include<cstdio>
#include<cstdlib>
#include<cstring>
int mn[60000],q;
void f(int n){
    int nx,nw=mn[n];
    char a[10],b[10];
    sprintf(a,"%d",n);
    strcpy(b,a);
    b[0]=a[1],b[1]=a[2],b[2]=a[0];  //A
    nx=atoi(b);
    if(mn[nx]<0 || mn[nx]>nw+1)     mn[nx]=nw+1,f(nx);
    strcpy(b,a);
    b[2]=a[4],b[3]=a[2],b[4]=a[3];  //B
    nx=atoi(b);
    if(mn[nx]<0 || mn[nx]>nw+1)     mn[nx]=nw+1,f(nx);
    strcpy(b,a);
    b[0]=a[2],b[1]=a[0],b[2]=a[1];  //C
    nx=atoi(b);
    if(mn[nx]<0 || mn[nx]>nw+1)     mn[nx]=nw+1,f(nx);
    strcpy(b,a);
    b[2]=a[3],b[3]=a[4],b[4]=a[2];  //D
    nx=atoi(b);
    if(mn[nx]<0 || mn[nx]>nw+1)     mn[nx]=nw+1,f(nx);
}
int main(){
    scanf("%d",&q);
    while(q--){
        int n;
        memset(mn,-1,sizeof(mn));
        scanf("%d",&n);
        mn[n]=0;    f(n);
        printf("%d\n",mn[12345]);
    }
    return 0;
}
