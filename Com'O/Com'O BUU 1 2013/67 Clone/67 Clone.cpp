//LCS : Longest Common Subsequence
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int mic[2010][2010],path[2010][2010];
char a[2010],b[2010],ans[2010];
int main(){
    int lena,lenb,i,j,k=0;
    scanf("%s %s",a,b);
    lena=strlen(a),lenb=strlen(b);
    for(i=0;i<lena;i++){
        for(j=0;j<lenb;j++){
            if(a[i]==b[j])
                mic[i+1][j+1]=mic[i][j]+1,path[i+1][j+1]=1;
            else
                mic[i+1][j+1]=max(mic[i+1][j],mic[i][j+1]);
        }
    }
    if(mic[lena][lenb]==0){
        printf("No Roma word\n");
        return 0;
    }
    for(i=lena,j=lenb;i>=0&&j>=0;){
        if(path[i][j]){
            ans[k++]=a[i-1];
            i--,j--;
        }
        else if(mic[i][j-1]>mic[i-1][j])    j--;
        else    i--;
    }
    for(i=k-1;i>=0;i--)
        printf("%c",ans[i]);
    printf("\n");
    return 0;
}
