#include<cstdio>
char a[3][20];
int chk[10],ans=1;
int main(){
    for(int i=0;i<3;i++)
        gets(a[i]);
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++)
            chk[j]=1;
        if(a[0][3*i+1]=='_'){
            chk[1]=0;   chk[4]=0;
        }
        if(a[1][3*i]=='|'){
            chk[1]=0;   chk[2]=0;
            chk[3]=0;   chk[7]=0;
        }
        if(a[1][3*i+1]=='_'){
            chk[1]=0;   chk[7]=0;
            chk[0]=0;
        }
        if(a[1][3*i+2]=='|'){
            chk[5]=0;   chk[6]=0;
        }
        if(a[2][3*i]=='|'){
            chk[1]=0;   chk[3]=0;
            chk[4]=0;   chk[5]=0;
            chk[7]=0;   chk[9]=0;
        }
        if(a[2][3*i+1]=='_'){
            chk[1]=0;   chk[4]=0;
            chk[7]=0;
        }
        if(a[2][3*i+2]=='|')
            chk[2]=0;
        int cnt=0;
        if(i==0)    cnt+=chk[0]+chk[1];
        else if(i==3){
            for(int j=0;j<6;j++)
                cnt+=chk[j];
        }
        else{
            for(int j=0;j<10;j++)
                cnt+=chk[j];
        }
        ans*=cnt;
    }
    printf("%d\n",ans);
    return 0;
}
