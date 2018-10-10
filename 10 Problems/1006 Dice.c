#include<stdio.h>
#include<string.h>
int dice[10],len;
char cmd[1010];
int main(){
    int n,i,j,a,b,c,d;
    scanf("%d",&n);
    while(n--){
        dice[0]=1,dice[1]=2,dice[2]=3,dice[3]=5,dice[4]=4,dice[5]=6;
        scanf(" %s",cmd);
        len=strlen(cmd);
        for(i=0;i<len;i++){
            if(cmd[i]=='F'){
                a=dice[0],b=dice[1],c=dice[3],d=dice[5];
                dice[0]=c,dice[1]=a,dice[3]=d,dice[5]=b;
            }
            if(cmd[i]=='B'){
                a=dice[0],b=dice[1],c=dice[3],d=dice[5];
                dice[0]=b,dice[1]=d,dice[3]=a,dice[5]=c;
            }
            if(cmd[i]=='L'){
                a=dice[0],b=dice[2],c=dice[4],d=dice[5];
                dice[0]=c,dice[2]=a,dice[4]=d,dice[5]=b;
            }
            if(cmd[i]=='R'){
                a=dice[0],b=dice[2],c=dice[4],d=dice[5];
                dice[0]=b,dice[2]=d,dice[4]=a,dice[5]=c;
            }
            if(cmd[i]=='C'){
                a=dice[1],b=dice[2],c=dice[3],d=dice[4];
                dice[1]=d,dice[2]=a,dice[3]=b,dice[4]=c;
            }
            if(cmd[i]=='D'){
                a=dice[1],b=dice[2],c=dice[3],d=dice[4];
                dice[1]=b,dice[2]=c,dice[3]=d,dice[4]=a;
            }
        }
        printf("%d ",dice[1]);
    }
    printf("\n");
    return 0;
}
