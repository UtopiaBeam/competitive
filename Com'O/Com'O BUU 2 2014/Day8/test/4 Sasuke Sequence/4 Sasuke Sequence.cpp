#include<stdio.h>
#include<algorithm>
using namespace std;
char a[30];
int p,k,b[30],c[30],cnt=0;
void per(int state){
    int i,chk=1;
    if(state==k && cnt<20000){
        chk=1,cnt++;
        for(i=1;i<k&&chk;i++){
            if((a[b[i]]=='a'||a[b[i]]=='e'||a[b[i]]=='i'||a[b[i]]=='o'||a[b[i]]=='u') &&
               (a[b[i-1]]=='a'||a[b[i-1]]=='e'||a[b[i-1]]=='i'||a[b[i-1]]=='o'||a[b[i-1]]=='u'))
               chk=0;
        }
        if(chk){
            for(i=0;i<k;i++)
                printf("%c",a[b[i]]);
            printf("\n");
        }
        return ;
    }
    for(i=0;i<p;i++)
        if(c[i]!=2 && i>=b[state-1]){
            c[i]=2;     b[state]=i;
            per(state+1);
            c[i]=0;
        }
}
int main(){
    int i;
    scanf("%d %d",&p,&k);
    for(i=0;i<p;i++)
        scanf(" %c",&a[i]);
    sort(a,a+p);
    per(0);
    return 0;
}
