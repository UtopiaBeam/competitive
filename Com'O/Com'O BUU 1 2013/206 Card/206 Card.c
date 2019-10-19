#include<stdio.h>
#include<string.h>
int cn[15],cs[5],len;
int main(){
    int i;
    for(i=0;i<51;i++){
        char a[5];
        scanf(" %s",a);
        len=strlen(a);
        if(len==3)    cn[10]++;
        else if(a[0]>='2' && a[0]<='9')  cn[a[0]-'0']++;
        else if(a[0]=='A')  cn[1]++;
        else if(a[0]=='J')  cn[11]++;
        else if(a[0]=='Q')  cn[12]++;
        else if(a[0]=='K')  cn[13]++;
        if(a[len-1]=='S')     cs[0]++;
        if(a[len-1]=='H')     cs[1]++;
        if(a[len-1]=='D')     cs[2]++;
        if(a[len-1]=='C')     cs[3]++;
    }
    for(i=1;i<=13;i++)
        if(cn[i]<4){
            if(i==1)    printf("A");
            else if(i<=10)  printf("%d",i);
            else if(i==11)  printf("J");
            else if(i==12)  printf("Q");
            else if(i==13)  printf("K");
        }
    if(cs[0]<13)    printf("S\n");
    if(cs[1]<13)    printf("H\n");
    if(cs[2]<13)    printf("D\n");
    if(cs[3]<13)    printf("C\n");
    return 0;
}
