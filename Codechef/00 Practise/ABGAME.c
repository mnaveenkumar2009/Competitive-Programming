int main()
{
    char s[100005];
    scanf("%s",s);
    while(~scanf("%s",s)){
        int n=strlen(s),len,xxx=1,prev,extra=0,nim=0;
        for(int i=0;i<n;i++)
            if(s[i]^'.'){
                if(xxx^=1)
                    if(prev^(s[i]&2))
                        nim^=i-len-1;
                    else
                        extra-=--prev*(i-len-1);
                prev=s[len=i]&2;
            }
        if(!xxx)
            extra-=--prev*(n-1-len);
        if(!extra)
            extra=nim;
        printf(extra>0?"A\n":"B\n");
    }
}