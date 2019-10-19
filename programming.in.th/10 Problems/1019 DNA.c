#include<stdio.h>
#include<string.h>
int mic[210][210];
int main(){
    char a[210],b[210],ans[210];
    int lena,lenb,i,j,max=0,in;
    memset(mic,0,sizeof(int));
    scanf(" %s %s",a,b);
    lena=strlen(a),lenb=strlen(b);
    for(i=0;i<lena;i++)
        for(j=0;j<lenb;j++){
            if(a[i]==b[j]){
                if(i==0||j==0)
                    mic[i][j]=1;
                else    mic[i][j]=mic[i-1][j-1]+1;
                if(mic[i][j]>max){
                    max=mic[i][j];
                    in=i;
                }
            }
            else    mic[i][j]=0;
        }
    for(i=in-max+1;i<=in;i++)
        printf("%c",a[i]);
    printf("\n");
    return 0;
}
