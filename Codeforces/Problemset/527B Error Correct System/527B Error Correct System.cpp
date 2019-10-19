#include<cstdio>
int s11[26],s12[26],s22[26][26];
char s1[200005],s2[200005];
int main(){
    int n,pt1=-1,pt2=-1;
    scanf("%d",&n);
    scanf("%s %s",s1,s2);
    for(int i=n;i>0;i--){
        s2[i]=s2[i-1];
        s1[i]=s1[i-1];
    }
    int mx=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(s1[i]==s2[i])    continue;
        cnt++;
        s11[s1[i]-'a']=i;
        s12[s2[i]-'a']=i;
        s22[s1[i]-'a'][s2[i]-'a']=i;
        if(i==0)printf("%d",s22[s1[i]-'a'][s2[i]-'a']);
        if(s22[s2[i]-'a'][s1[i]-'a']!=0){
            mx=2;
            pt1=s22[s2[i]-'a'][s1[i]-'a'];
            pt2=i;
        }
        if(s11[s2[i]-'a']!=0&&mx!=2){
            mx=1;
            pt1=s11[s2[i]-'a'];
            pt2=i;
        }
        if(s12[s1[i]-'a']!=0&&mx!=2){
            mx=1;
            pt1=s12[s1[i]-'a'];
            pt2=i;
        }
    }
    printf("%d\n%d %d",cnt-mx,pt1,pt2);
    return 0;
}
