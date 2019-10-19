#include<cstdio>
#include<cstring>
char str[30],a[2][15];
int s=-1,e,cnt[26],r,c,d;
int main(){
    scanf("%s",str);
    memset(a,0,sizeof(a));
    for(int i=0;str[i];i++)
        cnt[str[i]-'A']++;
    for(int i=0;str[i];i++)
        if(cnt[str[i]-'A']==2){
            if(s<0)     s=i;
            else        e=i;
        }
    d=e-s-1;
    if(d==0){
        printf("Impossible\n");
        return 0;
    }
    a[0][12-d/2]=str[s];
    int r1=0,p1=13-d/2,nw1=s+1,r2=1,p2=13-(d+1)/2,nw2=e-1;
    while(nw1<nw2){
        if(p1>12)       p1=12,r1=1;
        if(p2>12)       p2=12,r2=0;
        if(r1==0)       a[r1][p1++]=str[nw1++];
        else    a[r1][p1--]=str[nw1++];
        if(r2==1)       a[r2][p2++]=str[nw2--];
        else    a[r2][p2--]=str[nw2--];
    }
    nw2=e+1,p2=12-(d+1)/2;
    int r=1;
    while(str[nw2]){
        if(p2<0)   p2=0,r=0;
        if(r==0)    a[r][p2++]=str[nw2++];
        else        a[r][p2--]=str[nw2++];
    }
    nw2=0;
    while(str[nw2]){
        if(p2<0)   p2=0,r=0;
        if(r==0)    a[r][p2++]=str[nw2++];
        else        a[r][p2--]=str[nw2++];
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<13;j++)
            printf("%c",a[i][j]);
        printf("\n");
    }
    return 0;
}
