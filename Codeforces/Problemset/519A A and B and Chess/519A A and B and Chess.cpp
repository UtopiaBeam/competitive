#include<cstdio>
char a[10];
int main(){
    int cnt=0;
    for(int i=0;i<8;i++){
        scanf(" %s",a);
        for(int j=0;j<8;j++){
            if(a[j]=='Q')   cnt+=9;
            if(a[j]=='q')   cnt-=9;
            if(a[j]=='R')   cnt+=5;
            if(a[j]=='r')   cnt-=5;
            if(a[j]=='B'||a[j]=='N')   cnt+=3;
            if(a[j]=='b'||a[j]=='n')   cnt-=3;
            if(a[j]=='P')   cnt++;
            if(a[j]=='p')   cnt--;
        }
    }
    if(cnt>0)   printf("White\n");
    else if(cnt<0)  printf("Black\n");
    else    printf("Draw\n");
    return 0;
}
