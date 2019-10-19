#include<stdio.h>
#include<string.h>
int q;
char a[30],b[30];
int main(){
    int lena,lenb,i,j,k,marki,markj,chk=1,ch=0;
    scanf("%d",&q);
    for(k=1;k<=q;k++){
        scanf(" %s %s",a,b);
        lena=strlen(a),lenb=strlen(b);
        for(i=0;i<lena;i++)
            for(j=0;j<lenb;j++)
                if(a[i]==b[j])
                    marki=i,markj=j,chk=0;
        printf("%d %d\n",marki,markj);
        printf("CASE %d:\n",k);
        if(chk){
            printf("NO CROSS\n");
            continue;
        }
        for(i=0;i<lenb&&!chk;i++){
            for(j=0;j<lena;j++){
                if(j==markj)
                    printf("%c",b[i]);
                else if(i==marki)
                    printf("%c",a[j]);
                else    printf(".");
            }
            printf("\n");
        }
//        for(i=0;i<lenb&&!chk;i++)
//            for(j=0;j<lena;j++)
//                if(a[j]==b[i])
//                    marki=i,markj=j,ch=1;
//        for(i=0;i<lenb&&ch;i++){
//            for(j=0;j<lena;j++)
//                if(marki==i)
//                    printf("%c",a[i]);
//                else if(markj==j)
//                    printf("%c",b[j]);
//                else
//                    printf(".");
//            printf("\n");
//        }
    }
    return 0;
}
