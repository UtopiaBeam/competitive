#include<cstdio>
int a[30],b[30],c[30],mnb=1<<20,anb=0,anc=0;
char A[100005],B[100005],C[100005];
int main(){
    scanf(" %s %s %s",A,B,C);
    for(int i=0;A[i];i++)
        a[A[i]-'a']++;
    for(int i=0;B[i];i++)
        b[B[i]-'a']++;
    for(int i=0;C[i];i++)
        c[C[i]-'a']++;
    for(int i=0;i<26;i++)
        if(b[i] && mnb>a[i]/b[i])   mnb=a[i]/b[i];
    for(int i=0;i<=mnb;i++){
        int mnc=1<<20;
        for(int j=0;j<26;j++)
            if(c[j] && (a[j]-i*b[j])/c[j]<mnc)
                mnc=(a[j]-i*b[j])/c[j];
        if(anb+anc<i+mnc)   anb=i,anc=mnc;
    }
    for(int i=0;i<26;i++){
        if(b[i])    a[i]-=b[i]*anb;
        if(c[i])    a[i]-=c[i]*anc;
    }
    while(anb--)    printf("%s",B);
    while(anc--)    printf("%s",C);
    for(int i=0;i<26;i++)
        while(a[i]--)   printf("%c",i+'a');
    return 0;
}
