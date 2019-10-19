#include<cstdio>
#include<algorithm>
using namespace std;
int a[30],b[30],c[30],mnb1=1<<20,mnc1=1<<20,mnb2=1<<20,mnc2=1<<20,t1=0,t2=0;
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
        if(b[i])    mnb1=min(mnb1,a[i]/b[i]);
    if(mnb1==1<<20)     mnb1=0;
    t1=mnb1;
    for(int i=0;i<26;i++)
        a[i]-=mnb1*b[i];
    for(int i=0;i<26;i++)
        if(c[i])    mnc1=min(mnc1,a[i]/c[i]);
    if(mnc1==1<<20)     mnc1=0;
    t1+=mnc1;
    for(int i=0;i<26;i++)
        a[i]+=mnb1*b[i];
    for(int i=0;i<26;i++)
        if(c[i])    mnc2=min(mnc2,a[i]/c[i]);
    if(mnc2==1<<20)     mnc2=0;
    t2=mnc2;
    for(int i=0;i<26;i++)
        a[i]-=mnc2*c[i];
    for(int i=0;i<26;i++)
        if(b[i])    mnb2=min(mnb2,a[i]/b[i]);
    if(mnb2==1<<20)     mnb2=0;
    t2+=mnb2;
    for(int i=0;i<26;i++)
        a[i]+=mnc2*c[i];
    if(t1>=t2){
        for(int i=0;i<26;i++)
            a[i]-=b[i]*mnb1+c[i]*mnc1;
        while(mnb1--)   printf("%s",B);
        while(mnc1--)   printf("%s",C);
    }
    else{
        for(int i=0;i<26;i++)
            a[i]-=b[i]*mnb2+c[i]*mnc2;
        while(mnb2--)   printf("%s",C);
        while(mnc2--)   printf("%s",B);
    }
    for(int i=0;i<26;i++)
        while(a[i]--)   printf("%c",i+'a');
    return 0;
}
