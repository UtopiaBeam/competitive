#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[10010],b[10010];
int cmp[10010][10010];
int main(){
    int i,j,lena,lenb;
    scanf(" %s %s",a,b);
    strcpy(&a[1],a); strcpy(&b[1],b);
    lena=strlen(a),lenb=strlen(b);
    printf("%s\n%s\n",a,b);
//    for(i=1;i<=lena;i++)
//        for(j=1;j<=lenb;j++)
//            if(a[i]==b[j])
//                cmp[i][j]=cmp[i-1][j-1]+1;
//            else
//                cmp[i][j]=max(cmp[i-1][j],cmp[i][j-1]);
//    printf("%d\n",cmp[lena][lenb]);
    return 0;
}
