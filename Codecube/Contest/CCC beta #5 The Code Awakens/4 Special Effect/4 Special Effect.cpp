#include<cstdio>
int r,c;
char a[82][82];
void L(int i,int j){
    while(j>=0){
        if(a[i][j]=='.')    a[i][j]='-';
        else if(a[i][j]=='|')   a[i][j]='+';
        else if(a[i][j]!='+')   break;
        j--;
    }
}
void R(int i,int j){
    while(j<c){
        if(a[i][j]=='.')    a[i][j]='-';
        else if(a[i][j]=='|')   a[i][j]='+';
        else if(a[i][j]!='+')   break;
        j++;
    }
}
void U(int i,int j){
    while(i>=0){
        if(a[i][j]=='.')    a[i][j]='|';
        else if(a[i][j]=='-')   a[i][j]='+';
        else if(a[i][j]!='+')   break;
        i--;
    }
}
void D(int i,int j){
    while(i<r){
        if(a[i][j]=='.')    a[i][j]='|';
        else if(a[i][j]=='-')   a[i][j]='+';
        else if(a[i][j]!='+')   break;
        i++;
    }
}
int main(){
    scanf("%d %d",&c,&r);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(a[i][j]=='<')        L(i,j-1);
            else if(a[i][j]=='>')   R(i,j+1);
            else if(a[i][j]=='^')   U(i-1,j);
            else if(a[i][j]=='V')   D(i+1,j);
            else if(a[i][j]=='B')   a[i][j]='*';
        }
    for(int i=0;i<r;i++)
        printf("%s\n",a[i]);
    return 0;
}
