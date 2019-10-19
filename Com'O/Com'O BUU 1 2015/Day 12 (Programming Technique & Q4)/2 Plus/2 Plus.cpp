#include<cstdio>
#include<cstring>
char a[5005],b[5005],ans[5005],t,lans=0;
void plus(char *x,char *y){
    int lx=strlen(x),ly=strlen(y);
    if(lx<=ly){
        lans=ly;
        for(int i=0;i<lx;i++){
            ans[i]+=x[i]+y[i];
            ans[i+1]+=ans[i]/10,ans[i]%=10;
        }
        for(int i=lx;i<ly;i++){
            ans[i]+=y[i];
            if(i<ly-1)  ans[i+1]+=ans[i]/10,ans[i]%=10;
        }
    }
    else{
        lans=lx;
        for(int i=0;i<ly;i++){
            ans[i]+=x[i]+y[i];
            ans[i+1]+=ans[i]/10,ans[i]%=10;
        }
        for(int i=ly;i<lx;i++){
            ans[i]+=x[i];
            if(i<ly-1)  ans[i+1]+=ans[i]/10,ans[i]%=10;
        }
    }
}
void minus(char *x,char *y){
    int lx=strlen(x),ly=strlen(y);
}
int main(){
    scanf(" %s %s",a,b);
    int chka=1,chkb=1,la=strlen(a),lb=strlen(b);
    if(a[0]=='-')   strcpy(a,a+1),chka=-1,la--;
    if(b[0]=='-')   strcpy(b,b+1),chkb=-1,lb--;
    for(int i=0;i<la/2;i++)     t=a[i],a[i]=a[la-1-i],a[la-1-i]=t;
    for(int i=0;i<lb/2;i++)     t=b[i],b[i]=b[lb-1-i],b[lb-1-i]=t;
    for(int i=0;i<la;i++)   a[i]-='0',a[i]*=chka;
    for(int i=0;i<lb;i++)   b[i]-='0',b[i]*=chkb;
//    for(int i=la-1;i>=0;i--)    printf("%d",a[i]);
//    printf("\n");
//    for(int i=lb-1;i>=0;i--)    printf("%d",b[i]);
//    printf("\n");
    if(chka==chkb)      plus(a,b);
    else if(chka==-1)   minus(b,a);
    else    minus(a,b);
    for(int i=lans-1;i>=0;i--)    printf("%d",ans[i]);
    return 0;
}
