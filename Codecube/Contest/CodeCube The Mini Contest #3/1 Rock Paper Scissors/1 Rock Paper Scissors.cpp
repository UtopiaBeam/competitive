#include<cstdio>
#include<algorithm>
using namespace std;
int a[3],mx=0,chk=0;
int main(){
    for(int i=0;i<3;i++)
        scanf("%d",&a[i]);
    if(a[0]+a[1]+a[2]!=100)     printf("BUG\n");
    else{
        mx=max(max(a[0],a[1]),a[2]);
        for(int i=0;i<3;i++)
            if(a[i]==mx){
                if(chk){
                    printf("I DON'T KNOW\n");
                    return 0;
                }
                chk=i+1;
            }
        if(chk==1)  printf("PAPER\n");
        else if(chk==3)     printf("ROCK\n");
        else    printf("SCISSORS\n");
    }
    return 0;
}
