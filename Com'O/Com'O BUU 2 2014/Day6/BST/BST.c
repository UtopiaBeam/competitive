#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[300],n;
void add(int i,int num){
    if(a[i]==-1){
        a[i]=num;
        return ;
    }
    if(num<a[i])    add(2*i+1,num);
    else            add(2*i+2,num);
}
void pre(int i){
    if(a[i]!=-1){
        printf("%d\n",a[i]);
        pre(2*i+1);     pre(2*i+2);
    }
}
void pos(int i){
    if(a[i]!=-1){
        pos(2*i+1);     pos(2*i+2);
        printf("%d\n",a[i]);
    }
}
void inf(int i){
    if(a[i]!=-1){
        inf(2*i+1);
        printf("%d\n",a[i]);
        inf(2*i+2);
    }
}
int main(){
    char b[5];
    int i,num,j;
    memset(a,-1,sizeof(a));
    scanf("%s %d",b,&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        add(0,num);
    }
    if(!strcmp(b,"PRE"))    pre(0);
    if(!strcmp(b,"POS"))    pos(0);
    if(!strcmp(b,"INF"))    inf(0);
    if(!strcmp(b,"BRF")){
        for(i=0;i<256;i++)
            if(a[i]!=-1)
                printf("%d\n",a[i]);
    }
    return 0;
}
