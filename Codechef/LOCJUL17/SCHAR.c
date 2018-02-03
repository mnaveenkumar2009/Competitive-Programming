    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define INT_MAX 2600000
     
    int min ( int a, int b)
    {
        if(a<b)return (a);
        return (b);
    }
     
    int main() {
    int q,i=0,t,j=0;
    int n,m;
    scanf("%d",&t);
     
    while(t--)
    {
        char s[100009];
        scanf("%s",s);
        n = strlen(s);
        
        int a[26][100004],poin[26];
        f(i,26)poin[i]=0;
        f(i,n)
        {
            int dif = s[i] - 'a';
            a[dif][poin[dif]]=i;
            poin[dif]++;
        }
        int dp[n];
        f(i,n)dp[i]=INT_MAX;
        
        int mini[26];
        f(i,26)mini[i]=INT_MAX;
        
        
        dp[n-1]=0;
        dp[n-2]=abs(s[n-1]-s[n-2]);
        int dif = s[n-1] -'a';
        mini[dif]=0;
        dif = s[n-2] - 'a';
        mini[dif] = dp[n-2];
        
        f(i,n-2)
        {   //cout<<a[s[n-i-3]-'a'].size()<<endl;
            dif = s[n-i-3]-'a';
            
            dp[n-i-3] = min(dp[n-i-3] , mini[dif]);
            
            dp[n-i-3] = min(dp[n-i-3] , (dp[n-i-2]+abs(s[n-i-2]-s[n-i-3])) );
            
            mini[dif] = min(mini[dif],dp[n-i-3]);
        }
        //f(i,n)    {        cout<<dp[i]<<" ";    }cout<<endl;
        printf("%d\n",dp[0]);
    }
    	return 0;
    } 

