#include<stdio.h>
#include<string.h>
char l1[150],l2[150],s[150];
int main(){
    int lenl,lens,i,j,k;
    scanf("%d %d",&lenl,&lens);
    scanf(" %s %s %s",l1,l2,s);
    for(i=0;i<lenl;i++){
        for(j=lens-1;j>=0;j--){
            for(k=lens-1;k>=j;k--)
                if(s[k]<=l1[i] && l1[i]<=l2[i])   s[k]=l1[i];
                else if(s[k]<=l2[i] && l2[i]<=l1[i])  s[k]=l2[i];
                else if(s[k]>=l1[i] && l1[i]>=l2[i])   s[k]=l1[i];
                else if(s[k]>=l2[i] && l2[i]>=l1[i])  s[k]=l2[i];
        }
    }
    printf("%s\n",s);
    return 0;
}
