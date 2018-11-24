int main(){
    char s[100005];
    scanf("%s",s);
    while(~scanf("%s",s)){
        int n=strlen(s),c=0,d=1;
        for(int i=0;i<n;i++)
            if(s[i]==s[(i+1)%n]){
                c++;
                d^=i&1;
            }
        c|=2;
        if( c==2 && d )
            printf("yes\n");
        else
            printf("no\n");
    }
}