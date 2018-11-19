#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    char s[100005];
    while(~scanf("%s",s)){
        int n=strlen(s);
        if(n&1){
            printf("no\n");
        }
        else{
            int c=0,d1=-1,d2=-1;
            for(int i=0;i<n;i++){
                if(s[i]==s[(i+1)%n]){
                    c++;
                    if(d1+1)
                        d2=i;
                    else
                        d1=i;
                }
            }
            if(c<3&&(d2-d1)%2==0){
                printf("yes\n");                
            }
            else{
                printf("no\n");
            }
        }
    }
}