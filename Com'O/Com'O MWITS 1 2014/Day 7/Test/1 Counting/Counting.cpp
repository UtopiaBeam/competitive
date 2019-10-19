#include<stdio.h>
#include<string.h>
int main(){
    char a[1005];
    int cnt1=0,cnt2=0;
    freopen("counting.out","w",stdout);
    FILE *fp1=fopen("counting.in","r");
    while(fscanf(fp1," %s",a)!=EOF)  cnt1++;
    fclose(fp1);
    FILE *fp2=fopen("counting.in","r");
    while(fgets(a,1000,fp2)!=NULL)      cnt2++;
    printf("%d %d\n",cnt1,cnt2);
    fclose(fp2);
    return 0;
}
